import pygame
pygame.init()

# Need a window to draw on using pygame.
WINDOW = pygame.display.set_mode((500, 500))
# Give the window a title
pygame.display.set_caption("pygame tutorial")
# Setting up position for character
x = 50
y = 50
width = 40
height = 60
velocity = 5
# Main game loop to check for collisions, input events, etc.
RUNNING = True
while RUNNING:
    pygame.time.delay(100)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            RUNNING = False
pygame.quit()