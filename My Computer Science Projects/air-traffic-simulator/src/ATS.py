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
    def __init__(self, position, speed, type, flight_number):
        self.position = position
        self.speed = speed
        self.type = type
        self.flight_number = flight_number

def spawn_aircraft(waypoints):
    spawn_point = random.choice(waypoints)
    speed = random.randint(1, 5)
    aircraft_type = random.choice(["Cessna", "Boeing", "Airbus"])
    flight_number = random.randint(100, 999)
    new_aircraft = Aircraft(spawn_point, speed, aircraft_type, flight_number)
    return new_aircraft