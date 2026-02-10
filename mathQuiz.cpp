#include <SDL2/SDL.h>
#include <cstdlib>
#include <ctime>
#include <string>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int a, b, correct,Answer;
char op;
std::string userInput = "";

/*
 Segment index:
 0 = A (top)
 1 = B (top-right)
 2 = C (bottom-right)
 3 = D (bottom)
 4 = E (bottom-left)
 5 = F (top-left)
 6 = G (middle)
*/

bool digits[10][7] = {
    {1,1,1,1,1,1,0}, {0,1,1,0,0,0,0}, {1,1,0,1,1,0,1},
    {1,1,1,1,0,0,1}, {0,1,1,0,0,1,1}, {1,0,1,1,0,1,1},
    {1,0,1,1,1,1,1}, {1,1,1,0,0,0,0}, {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};

void drawDigit(int digit, int x, int y, int size) {
    int t = size / 5;
    int l = size;

    SDL_Rect seg[7] = {
        {x+t, y, l, t},
        {x+l+t, y+t, t, l},
        {x+l+t, y+l+2*t, t, l},
        {x+t, y+2*l+2*t, l, t},
        {x, y+l+2*t, t, l},
        {x, y+t, t, l},
        {x+t, y+l+t, l, t}
    };

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    for (int i = 0; i < 7; i++)
        if (digits[digit][i])
            SDL_RenderFillRect(renderer, &seg[i]);
}

void drawNumber(int number, int x, int y, int size) {
    if (number == 0) {
        drawDigit(0, x, y, size);
        return;
    }

    int offset = 0;
    while (number > 0) {
        int d = number % 10;
        drawDigit(d, x - offset, y, size);
        offset += size + 20;
        number /= 10;
    }
}

void drawOperator(char op, int x, int y) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    if (op == '+') {
        SDL_Rect h = {x, y+20, 40, 8};
        SDL_Rect v = {x+16, y, 8, 40};
        SDL_RenderFillRect(renderer, &h);
        SDL_RenderFillRect(renderer, &v);
    }
    else if (op == '-') {
        SDL_Rect h = {x, y+20, 40, 8};
        SDL_RenderFillRect(renderer, &h);
    }
    else if (op == '*') {
        SDL_Rect r1 = {x, y, 40, 8};
        SDL_Rect r2 = {x, y+32, 40, 8};
        SDL_RenderFillRect(renderer, &r1);
        SDL_RenderFillRect(renderer, &r2);
    }
    else if (op == '/') {
        SDL_Rect dot1 = {x+18, y, 6, 6};
        SDL_Rect dot2 = {x+18, y+34, 6, 6};
        SDL_Rect mid = {x+10, y+18, 20, 4};
        SDL_RenderFillRect(renderer, &dot1);
        SDL_RenderFillRect(renderer, &mid);
        SDL_RenderFillRect(renderer, &dot2);
    }
}

void generateQuestion() {
    int choice = rand() % 4;
    a = rand() % 10 + 1;
    b = rand() % 9 + 1; 

    if (choice == 0) {
            op = '+';
            correct = a + b;
        } 
        else if (choice == 1) {
            op = '-';
            correct = a - b;
        } 
        else if (choice == 2){
            op = '*';
            correct = a * b;
        }
         else {
            op = '/';

            // Make division exact
            correct = a;
            b = rand() % 9 + 1;   // b ≠ 0
            a = correct * b;      // a divisible by b
        }

        cout << "What is " << a << " " << op << " " << b << "? ";
        cin >> answer;

        if (answer == correct) {
            cout << "Correct!\n\n";
            score++;
        } else {
            cout << "Wrong answer \n";
            cout << "Correct answer was: " << correct << endl;
            break;
        }
    }

    cout << "Your final score: " << score << endl;
}
}
int main(int argc, char* argv[]) {
    srand(time(0));
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Math Quiz (7-Segment)",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    generateQuestion();
    SDL_StartTextInput();

    bool running = true;
    SDL_Event e;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) running = false;

            if (e.type == SDL_TEXTINPUT) {
                if (isdigit(e.text.text[0]))
                    userInput += e.text.text;
            }

            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_BACKSPACE && !userInput.empty())
                    userInput.pop_back();

                if (e.key.keysym.sym == SDLK_RETURN) {
                    if (userInput.empty() || stoi(userInput) != correctAnswer)
                        running = false;
                    else {
                        userInput = "";
                        generateQuestion();
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        drawNumber(a, 200, 150, 50);
        drawOperator(op, 300, 170);
        drawNumber(b, 380, 150, 50);

        if (!userInput.empty())
            drawNumber(stoi(userInput), 300, 320, 50);

        SDL_RenderPresent(renderer);
    }

    SDL_Quit();
    return 0;
}
