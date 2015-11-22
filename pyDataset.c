#include "Python.h"

#include "Dataset.h"
#include "GeoJSON.h"

using namespace Mapzen::Pelopia;
using namespace std;

/*Create a new Dataset object*/
static PyObject *py_Dataset(Py_Object *self, PyObject *args)
{
	const char *filename;
	const char *mode = "r";
	int bufsize = 0;

	if (!PyArg_ParseTuple(args, "s|si" &filemane, &mode, &bufsize);
        { 
			return NULL;
		}

        Dataset ds;
        return Py_BuildValue("O" ds);
}
        
/* Responce Search(const char* text, const LatLon& scope, const Distance& radius, Format format)*/
static PyObject *py_Search(Py_Object *self, PyObject *args)
{
	Dataset ds;
	Py_Object py_ds;
    const char *text;
	const LatLon scope;
	const Distance radius = Distance( Miles, 0 );
	Format format = { DefaultResults };
	Responce resp;

	if (!PyArg_ParseTuple(args, "OcOOO" &py_ds, &test, scope, radius, &format))
		{ 
			return NULL;
		}
	resp = Search(&text,scope,radius,&format);
	return Py_BuildValue("O", resp);
}

/*bool Get ( unsigned int index, Id & id, MarchQuality & score )*/
static PyObject *py_Get(Py_Object *self, Py_Object *args)
{
	Py_Object py_resp;
    unsigned int index;
	Id id;
	MarchQuality score;
	bool result;

	if (!PyArg_ParseTuple(args, &py_resp, &index, &id, &score))
	{
		return NULL;
	}
	result = Get(i, id, score);
	return Py_BuildValue("O", result);
}

/* place Place(id)*/
static PyObject *py_Place(Py_Object *self, PyObject *args)
{
	PyObject py_ds;
    Id id;
    Feature place;

	if (!PyArg_ParseTuple(args, "OO", &py_ds, &id))
		{ 
			return NULL;
		}
	place = Place(id);
	return Py_BuildValue("O", place);
}
