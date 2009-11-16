#include <glib.h>
#include <glib-object.h>

#include "libindicator/indicator.h"
#include "libindicator/indicator-object.h"

#define DUMMY_INDICATOR_SIMPLE_TYPE            (dummy_indicator_simple_get_type ())
#define DUMMY_INDICATOR_SIMPLE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), DUMMY_INDICATOR_SIMPLE_TYPE, DummyIndicatorSimple))
#define DUMMY_INDICATOR_SIMPLE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), DUMMY_INDICATOR_SIMPLE_TYPE, DummyIndicatorSimpleClass))
#define IS_DUMMY_INDICATOR_SIMPLE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DUMMY_INDICATOR_SIMPLE_TYPE))
#define IS_DUMMY_INDICATOR_SIMPLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DUMMY_INDICATOR_SIMPLE_TYPE))
#define DUMMY_INDICATOR_SIMPLE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), DUMMY_INDICATOR_SIMPLE_TYPE, DummyIndicatorSimpleClass))

typedef struct _DummyIndicatorSimple      DummyIndicatorSimple;
typedef struct _DummyIndicatorSimpleClass DummyIndicatorSimpleClass;

struct _DummyIndicatorSimpleClass {
	IndicatorObjectClass parent_class;
};

struct _DummyIndicatorSimple {
	IndicatorObject parent;
};

GType dummy_indicator_simple_get_type (void);

INDICATOR_SET_VERSION
INDICATOR_SET_TYPE(DUMMY_INDICATOR_SIMPLE_TYPE)

GtkLabel *
get_label (IndicatorObject * io)
{
	return GTK_LABEL(gtk_label_new("Simple Item"));
}

GtkImage *
get_icon (IndicatorObject * io)
{
	return GTK_IMAGE(gtk_image_new());
}

GtkMenu *
get_menu (IndicatorObject * io)
{
	GtkMenu * main_menu = GTK_MENU(gtk_menu_new());
	GtkWidget * loading_item = gtk_menu_item_new_with_label("Loading...");
	gtk_menu_shell_append(GTK_MENU_SHELL(main_menu), loading_item);
	gtk_widget_show(GTK_WIDGET(loading_item));

	return main_menu;
}

static void dummy_indicator_simple_class_init (DummyIndicatorSimpleClass *klass);
static void dummy_indicator_simple_init       (DummyIndicatorSimple *self);
static void dummy_indicator_simple_dispose    (GObject *object);
static void dummy_indicator_simple_finalize   (GObject *object);

G_DEFINE_TYPE (DummyIndicatorSimple, dummy_indicator_simple, INDICATOR_OBJECT_TYPE);

static void
dummy_indicator_simple_class_init (DummyIndicatorSimpleClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->dispose = dummy_indicator_simple_dispose;
	object_class->finalize = dummy_indicator_simple_finalize;

	IndicatorObjectClass * io_class = INDICATOR_OBJECT_CLASS(klass);

	io_class->get_label = get_label;
	io_class->get_image = get_icon;
	io_class->get_menu = get_menu;

	return;
}

static void
dummy_indicator_simple_init (DummyIndicatorSimple *self)
{

	return;
}

static void
dummy_indicator_simple_dispose (GObject *object)
{

	G_OBJECT_CLASS (dummy_indicator_simple_parent_class)->dispose (object);
	return;
}

static void
dummy_indicator_simple_finalize (GObject *object)
{

	G_OBJECT_CLASS (dummy_indicator_simple_parent_class)->finalize (object);
	return;
}