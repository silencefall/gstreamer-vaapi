/*
 *  gstvaapisurfacepool.h - Gst VA surface pool
 *
 *  gstreamer-vaapi (C) 2010 Splitted-Desktop Systems
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#ifndef GST_VAAPI_SURFACE_POOL_H
#define GST_VAAPI_SURFACE_POOL_H

#include <gst/gstcaps.h>
#include <gst/vaapi/gstvaapidisplay.h>
#include <gst/vaapi/gstvaapisurface.h>

G_BEGIN_DECLS

#define GST_VAAPI_TYPE_SURFACE_POOL \
    (gst_vaapi_surface_pool_get_type())

#define GST_VAAPI_SURFACE_POOL(obj)                             \
    (G_TYPE_CHECK_INSTANCE_CAST((obj),                          \
                                GST_VAAPI_TYPE_SURFACE_POOL,    \
                                GstVaapiSurfacePool))

#define GST_VAAPI_SURFACE_POOL_CLASS(klass)                     \
    (G_TYPE_CHECK_CLASS_CAST((klass),                           \
                             GST_VAAPI_TYPE_SURFACE_POOL,       \
                             GstVaapiSurfacePoolClass))

#define GST_VAAPI_IS_SURFACE_POOL(obj) \
    (G_TYPE_CHECK_INSTANCE_TYPE((obj), GST_VAAPI_TYPE_SURFACE_POOL))

#define GST_VAAPI_IS_SURFACE_POOL_CLASS(klass) \
    (G_TYPE_CHECK_CLASS_TYPE((klass), GST_VAAPI_TYPE_SURFACE_POOL))

#define GST_VAAPI_SURFACE_POOL_GET_CLASS(obj)                   \
    (G_TYPE_INSTANCE_GET_CLASS((obj),                           \
                               GST_VAAPI_TYPE_SURFACE_POOL,     \
                               GstVaapiSurfacePoolClass))

typedef struct _GstVaapiSurfacePool           GstVaapiSurfacePool;
typedef struct _GstVaapiSurfacePoolPrivate    GstVaapiSurfacePoolPrivate;
typedef struct _GstVaapiSurfacePoolClass      GstVaapiSurfacePoolClass;

struct _GstVaapiSurfacePool {
    /*< private >*/
    GObject parent_instance;

    GstVaapiSurfacePoolPrivate *priv;
};

struct _GstVaapiSurfacePoolClass {
    /*< private >*/
    GObjectClass parent_class;
};

GType
gst_vaapi_surface_pool_get_type(void);

GstVaapiSurfacePool *
gst_vaapi_surface_pool_new(GstVaapiDisplay *display, GstCaps *caps);

GstCaps *
gst_vaapi_surface_pool_get_caps(GstVaapiSurfacePool *pool);

void
gst_vaapi_surface_pool_set_caps(GstVaapiSurfacePool *pool, GstCaps *caps);

GstVaapiSurface *
gst_vaapi_surface_pool_new_surface(GstVaapiSurfacePool *pool);

void
gst_vaapi_surface_pool_free_surface(
    GstVaapiSurfacePool *pool,
    GstVaapiSurface     *surface
);

G_END_DECLS

#endif /* GST_VAAPI_SURFACE_POOL_H */
