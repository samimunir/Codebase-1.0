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
import pygame.font
pygame.font.init()
font = pygame.font.Font(None, 30)

def draw_text(screen, text, color, position, font_size = 30):
    font_obj = font.render(text, True, color)
    text_rect = font_obj.get_rect(center = position)
    screen.blit(font_obj, text_rect)
# pygame.init()
# screen_width = 800
# screen_height = 600
# screen = pygame.display.set_mode((screen_width, screen_height))

#
#   Drawing waypoints as circles on the map.
#   - loop through each waypoint.
#
# for waypoint in waypoints:
#     # Set the circle color to blue.
#     color = (0, 0, 255)
#     # Set the circle radius to 5px
#     radius = 5
#     # Draw the circle to represent the waypoint onto the map.
#     pygame.draw.circle(screen, color, waypoint, radius)
# # Update the entire screen after drawing all waypoints.
# pygame.display.flip()

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

MIN_SEPARATION_DISTANCE = 20

class Aircraft:
    def __init__(self, position, speed, type, flight_number, route):
        self.position = position
        self.speed = speed
        self.type = type
        self.flight_number = str(flight_number)
        self.route = route

def spawn_aircraft(waypoints):
    spawn_point = random.choice(waypoints)
    speed = random.randint(10, 20)
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
    if len(aircraft.route) == 0:
        return
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

aircraft_colors = {"Cessna": (255, 255, 255), "Boeing": (0, 255, 0), "Airbus": (255, 0, 0)}

def draw_aircraft(screen, aircraft):
    color = aircraft_colors.get(aircraft.type, (255, 255, 255)) # Default white if type not found
    radius = 5
    pygame.draw.circle(screen, color, aircraft.position, radius)
    text_pos = (aircraft.position[0], aircraft.position[1] - 15)
    draw_text(screen, aircraft.flight_number, (255, 255, 255), text_pos, font_size = 20)

def check_for_collisions(aircraft_list):
    for i in range(len(aircraft_list)):
        for j in range(i + 1, len(aircraft_list)):
            aircraft_1 = aircraft_list[i]
            aircraft_2 = aircraft_list[j]
            distance_between = distance(aircraft_1.position, aircraft_2.position)
            if distance_between < MIN_SEPARATION_DISTANCE:
                print(f"Collision detected between aircraft {aircraft_1.flight_number} and {aircraft_2.flight_number}")
                del aircraft_list[j]
                break

def draw_triangle(screen, position, radius, color):
    angle = math.pi / 3
    v1_x = position[0] + radius * math.cos(angle)
    v1_y = position[1] + radius * math.sin(angle)
    v2_x = position[0] - radius * math.cos(angle)
    v2_y = position[1] + radius * math.sin(angle)
    v3_x = position[0]
    v3_y = position[1] - radius * math.sqrt(3) / 2
    pygame.draw.polygon(screen, color, [(v1_x, v1_y), (v2_x, v2_y), (v3_x, v3_y)])

def main():
    pygame.init()
    screen_width = 800
    screen_height = 600
    screen = pygame.display.set_mode((screen_width, screen_height))
    clock = pygame.time.Clock()
    aircraft_list = []
    for _ in range(3):
        new_aircraft = spawn_aircraft(waypoints)
        aircraft_list.append(new_aircraft)
    
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        screen.fill((0, 0, 0))
        for aircraft in aircraft_list:
            dt = clock.tick(120) / 1000.0
            move_aircraft(aircraft, dt)
            draw_aircraft(screen, aircraft)
        
        check_for_collisions(aircraft_list)
        
        for waypoint in waypoints:
            # # Set the circle color to blue.
            # color = (0, 0, 255)
            # # Set the circle radius to 5px
            # radius = 10
            # # Draw the circle to represent the waypoint onto the map.
            # pygame.draw.circle(screen, color, waypoint, radius)
            draw_triangle(screen, waypoint, 10, (0, 255, 0))
        # Update the entire screen after drawing all waypoints.
        pygame.display.flip()
        # Control animation speed (optional)
        clock.tick(120) # update 60 times per second.
    pygame.quit()

if __name__ == "__main__":
    main()