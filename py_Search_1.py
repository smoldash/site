import pelopia
from pelopia import Dataset
from pelopia import GeoJSON


ds = Dataset("NYC.pelopia")
resp = ds.Search("Mapzen", LatLon(40.7507545 -73.9939152))
for i in resp:
	Id id
	MatchQuality score
    resp.get(i, id, score)     
    Feature place = ds.Place(id)
    print(place.Name, place.Address)

if __name__ == '__main__':
	main()