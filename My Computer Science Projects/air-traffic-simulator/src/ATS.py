#
#   Data structure: this Python list is used to store waypoints.
#   - each element in the list is a tuple containing the (x, y)
#       coordinates of a waypoint location.
#
waypoints = [(100, 50), (250, 150), (400, 100), (550, 200)]

#
#   Map visualization using pygame module/library.
#   - initializing pygame and setting the window size.
#
import pygame
pygame.init()
screen_width = 800
screen_height = 600
screen = pygame.display.set_mode((screen_width, screen_height))

#
#   Drawing waypoints as circles on the map.
#   - loop through each waypoint.
#
for waypoint in waypoints:
    # Set the circle color to blue.
    color = (0, 0, 255)
    # Set the circle radius to 5px
    radius = 5
    # Draw the circle to represent the waypoint onto the map.
    pygame.draw.circle(screen, color, waypoint, radius)
# Update the entire screen after drawing all waypoints.
pygame.display.flip()

#
#   Defining Aircraft class to represent individual aircrafts in the
#       simulation. The class attributes can include:
#       - position
#       - speed
#       - altitude
#       - direction
#       - route
#       - type
#       - flight_number
import random

class Aircraft:
    def __init__(self, position, speed, type, flight_number, route):
        self.position = position
        self.speed = speed
        self.type = type
        self.flight_number = flight_number
        self.route = route

def spawn_aircraft(waypoints):
    spawn_point = random.choice(waypoints)
    speed = random.randint(1, 5)
    aircraft_type = random.choice(["Cessna", "Boeing", "Airbus"])
    flight_number = random.randint(100, 999)
    new_aircraft = Aircraft(spawn_point, speed, aircraft_type, flight_number, [])
    new_aircraft.route = generate_route(waypoints, spawn_point)
    return new_aircraft

def generate_route(waypoints, spawn_point):
    available_waypoints = waypoints.copy()
    available_waypoints.remove(spawn_point)
    start_point = random.choice(available_waypoints)
    end_point = random.choice(available_waypoints)
    while start_point == end_point:
        end_point = random.choice(available_waypoints)
    num_waypoints = random.randint(1, 3)
    intermediate_waypoints = random.sample(available_waypoints, num_waypoints)
    route = [start_point] + intermediate_waypoints + [end_point]
    return route

import math
def distance(point1, point2):
    x1, y1 = point1
    x2, y2 = point2
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

def move_aircraft(aircraft, dt):
    next_waypoint = aircraft.route[0]
    direction_vector = (next_waypoint[0] - aircraft.position[0], next_waypoint[1] - aircraft.position[1])
    magnitude = math.sqrt(sum(value ** 2 for value in direction_vector))
    if magnitude > 0:
        direction_vector = tuple(v / magnitude for v in direction_vector)
    movement = tuple(d * aircraft.speed * dt for d in direction_vector)
    aircraft.position = (aircraft.position[0] + movement[0], aircraft.position[1] + movement[1])
    # Check if waypoint is reached (adjust threshold based on your scale).
    if distance(aircraft.position, aircraft.route[0]) < 5:
        aircraft.route.pop(0)