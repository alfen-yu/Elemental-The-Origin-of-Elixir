#include "Game.h"

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags)
{
    // initialize SDL
    int initialiser = SDL_Init(SDL_INIT_EVERYTHING);

    if (initialiser >= 0)
    { // returns -1 if unsuccessful
        // if initialisation is successful then create our window
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        // if window was a success then create renderer
        if (window != NULL)
        {
            renderer = SDL_CreateRenderer(window, -1, 0);
            // textureManager.load("assests/mainPlayer.png", "hero", renderer);
            // textureManager.load("assests/gameImages/NPCS/Pet Cats Pack/Cat-1/Cat-1-Run.png", "cat", renderer);
            if (!TheTextureManager::Instance()->load("assests/mainPlayer.bmp",
                                                     "hero", renderer))
            {
                return false;
            }

            if (!TheTextureManager::Instance()->load("assests/gameImages/NPCS/Pet Cats Pack/Cat-1/Cat-1-Run.png",
                                                     "cat", renderer))
            {
                return false;
            }
        }
        else
        {
            std::cout << "SDL could not create renderer! SDL_Error: %s\n", SDL_GetError();
            // SDL was unable to create a window
            return false;
        }
    }
    else
    {
        std::cout << "SDL could not create window! SDL_Error: %s\n", SDL_GetError();
        return false; // SDL was unable to create window and returns false
    }

    running = true;
    return true; // returns true if the function was a success
}

// handling user inputs and events
void Game::handleEvents()
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT: // handles the quit functionality, on click the x button
            running = false;
            break;
        default:
            break;
        }
    }
}

// rendering on the screen
void Game::render()
{
    if (renderer != NULL)
    {
        // if everyting works fine then draw on the window
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // gives the color to the renderer
        SDL_RenderClear(renderer);                            // cleans the renderer to draw the color

        TheTextureManager::Instance()->draw("hero", 0, 0, 32, 48, renderer);
        TheTextureManager::Instance()->drawFrame("hero", 100, 100, 32, 48, 1, currentFrame, renderer);
        TheTextureManager::Instance()->drawFrame("cat", 200, 200, 50, 50, 1, catFrame, renderer);

        SDL_RenderPresent(renderer); // presents the color on the screen
    }
    else
    {
        std::cout << "issues with the renderer! SDL_Error: %s\n", SDL_GetError();
    }
}

void Game::update()
{
    currentFrame = int((SDL_GetTicks() / 100) % 4);
    catFrame = int((SDL_GetTicks() / 100) % 8);
}

void Game::clean()
{
    TheTextureManager::Instance()->clean();
    SDL_DestroyWindow(window);     // frees up the space taken by the window
    SDL_DestroyRenderer(renderer); // frees up the space taken by the renderer
    renderer = nullptr;
    window = nullptr;
    SDL_Quit(); // cleans SDL
    std::cout << "cleaned the game \n";
}

Game::~Game() = default;