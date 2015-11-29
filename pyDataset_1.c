#include "Python.h"

#include "Dataset.h"
#include "GeoJSON.h"

using namespace Mapzen::Pelopia;
using namespace std;


/*Create a new Dataset object*/
static PyObject *py_Dataset(Py_Object *self, PyObject *args)
{
	const char *filename;
	Dataset ds;
		if (!PyArg_ParseTuple(args, "s", &filename);
        { 
			return NULL;
		}

        Dataset ds (filename);
        return Py_BuildValue("O", ds);  
}
                                                
                                                 /* Python code: ds = Dataset(NYC.Pelopia) */  

/* Responce Search(const char* text, const LatLon& scope, const Distance& radius, Format format)*/
static PyObject *py_Search(Py_Object *self, PyObject *args)
{
	Py_Object *self;
	const char *text;
	double lat;
	double lon;
	double radius;
	int format;
	Responce resp;

	if (!PyArg_ParseTuple(args, "Ocdddi", &self, & text, &lat, &lon, &radius, &format))
		{ 
			return NULL;
		}
	resp = self.Serch(text, LatLon(lat,lon), Distance(Miles, radius), Format(format));
	return Py_BuildValue("O", resp);
}

                                               /* resp = ds.Search(text, Latlon(lat,lon),radius, format) */

/*bool Get ( unsigned int index, Id & id, MarchQuality & score )*/
static PyObject *py_Get(Py_Object *self, Py_Object *args)
{
    Py_Object *self;
	unsigned int index;
	Id id;
	MarchQuality score;
	bool result;

	if (!PyArg_ParseTuple(args, 'OiOO', @self, &index, &id, &score))
	{
		return NULL;
	}
	result = self.Get(i, id, score);
	return Py_BuildValue("O", result);
}
                                  
                                   /* for i in resp: 
                                          resp.Get(i, id, score */
/* place Place(id)*/
static PyObject *py_Place(Py_Object *self, PyObject *args)
{
	Py_Object *self;
	Id id;
    Feature place;

	if (!PyArg_ParseTuple(args, "OO", &self, &id))
		{ 
			return NULL;
		}
	place = self.Place(id);
	return Py_BuildValue("O", place);
}
                                    /* place = ds.Place(id) */