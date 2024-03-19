import pygame
pygame.init()

# Need a window to draw on using pygame.
WINDOW = pygame.display.set_mode((500, 500))
# Give the window a title
pygame.display.set_caption("pygame tutorial")
# Setting up position for character (top-left of window is (0, 0) --> (0 + x, 0 + y))
x = 50
y = 450
width = 40
height = 60
velocity = 5
isJump = False
jumpCount = 10
# Main game loop to check for collisions, input events, etc.
RUNNING = True
while RUNNING:
    pygame.time.delay(100)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            RUNNING = False
    KEYS = pygame.key.get_pressed() # list of pygame key events
    if KEYS[pygame.K_LEFT] and x > velocity:
        x -= velocity
    if KEYS[pygame.K_RIGHT] and x + width < 500:
        x += velocity
    if not(isJump):
        if KEYS[pygame.K_UP] and y > velocity:
            y -= velocity
        if KEYS[pygame.K_DOWN] and y + height < 500:
            y += velocity
        if KEYS[pygame.K_SPACE]:
            isJump = True
    else:
        if jumpCount >= -10:
            neg = 1
            if jumpCount < 0:
                neg = -1
            y -= (jumpCount ** 2) * 0.5 * neg
            jumpCount -= 1
        else:
            isJump = False
            jumpCount = 10
    WINDOW.fill((0, 0, 0))
    pygame.draw.rect(WINDOW, (255, 0, 0), (x, y, width, height))
    pygame.display.update()

pygame.quit()