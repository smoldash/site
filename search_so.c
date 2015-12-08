
#include <pelopia/Dataset.h>
#include <pelopia/GeoJSON.h>

using namespace Mapzen::Pelopia;
using namespace std;

void createDataset(const char *filename)
{
     Dataset *ds = new Dataset(filename);
     return ds;
}


void Search_py(void *ds, 
	const char *text, 
	const double lat, 
	const double lon, 
	const double radius, 
	int format)
{
    Dataset *ds_c = (Dataset*)ds;
	
	Responce resp;

	return resp = ds_c -> Search(text, LatLon(lat,lon), Distance(Miles, radius), Format(format));
}

void Get_py(void *resp, unsigned int index, Id & id, MatchQuality & score)
{
	Responce resp_c = (Responce*)resp;
    unsigned int index;
	Id id;
	MarchQuality score;
	bool result;

	return result = resp_c -> Get(i, id, score);
}

void Place_py(void *ds, Id & id)
{
	Dataset *ds_c = (Dataset*)ds;
    Id id;
    Feature place;
	
	return place = ds_c -> Place(id);
}
