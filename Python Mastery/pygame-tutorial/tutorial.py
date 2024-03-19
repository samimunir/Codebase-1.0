import pygame
pygame.init()

# Need a window to draw on using pygame.
WINDOW = pygame.display.set_mode((500, 500))
# Give the window a title
pygame.display.set_caption("pygame tutorial")
# Setting up position for character (top-left of window is (0, 0) --> (0 + x, 0 + y))
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
    KEYS = pygame.key.get_pressed() # list of pygame key events
    if KEYS[pygame.K_LEFT]:
        x -= velocity
    if KEYS[pygame.K_RIGHT]:
        x += velocity
    if KEYS[pygame.K_UP]:
        y -= velocity
    if KEYS[pygame.K_DOWN]:
        y += velocity
    WINDOW.fill((0, 0, 0))
    pygame.draw.rect(WINDOW, (255, 0, 0), (x, y, width, height))
    pygame.display.update()

pygame.quit()