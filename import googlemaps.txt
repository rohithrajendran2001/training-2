import googlemaps
from googlemaps import Client

# Replace 'YOUR_API_KEY' with your actual Google Maps API key
gmaps = Client(key='AIzaSyADHpKLzhfWQYYUE5m4zjjVDJX3AbDgbcs')

# Get your current location using geolocation
location = gmaps.geolocate()

# Define the custom map that you want to search
map_id = 'https://www.google.com/maps/d/edit?mid=16CuNs4KRb_jMOYrBQtvWnrkiKQdsek8&usp=sharing'

# Retrieve the list of markers on the custom map
markers = gmaps.places_nearby(location, keyword=None, radius=10000, type=None, pagetoken=None)

# Find the nearest marker to your current location
nearest_marker = None
nearest_distance = float('inf')
for marker in markers['results']:
    marker_location = marker['geometry']['location']
    distance = ((location['location']['lat'] - marker_location['lat']) ** 2 + (location['location']['lng'] - marker_location['lng']) ** 2) ** 0.5
    if distance < nearest_distance:
        nearest_distance = distance
        nearest_marker = marker

# Print the name and address of the nearest marker
print('Nearest Marker:', nearest_marker['name'])
print('Address:', nearest_marker['vicinity'])
