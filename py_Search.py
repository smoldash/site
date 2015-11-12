import pelopia
from pelopia import Dataset
from pelopia import GeoJSON


ds = Dataset("NYC.pelopia")
resp = ds.Search("Mapzen", LatLon(40.7507545 -73.9939152))
index = input()
id = resp.get(index)     #if return id, score return will be obj
Feature place = ds.Place(id)
print(place.Name, place.Address)

if __name__ == '__main__':
	main()