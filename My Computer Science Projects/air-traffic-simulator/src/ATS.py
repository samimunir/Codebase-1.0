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