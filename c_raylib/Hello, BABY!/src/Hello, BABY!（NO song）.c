#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>
#include <math.h>

int main() {
    //Set the window
    InitWindow(900, 950, "Hello, BITCH!");
    SetTargetFPS(60);

    //Create and write a file
    const char* fileName = "NEVER FORGOT ME.txt";
    FILE *file = fopen(fileName, "w");
    if (!file) {
        TraceLog(LOG_ERROR, "Failed to create file!");
        CloseWindow();
        return 1;
    }else{
    const char* content = 
        "I love you too.\n"
        "Je t'aime aussi.\n"
        "Do you like me too?\n"
        "Tu m'aimes aussi?\n";
    fwrite(content, sizeof(char), strlen(content), file);
    fclose(file);
    }

    //Read a file
    file = fopen(fileName, "r");
    char lines[4][100]; 
    int lineCount = 0;
    if(file){
        while (lineCount < 4 && fgets(lines[lineCount], 100, file) != NULL) {
            size_t len = strlen(lines[lineCount]);
            if (len > 0 && lines[lineCount][len - 1] == '\n') {
                lines[lineCount][len - 1] = '\0';
            }
            lineCount++;
        }
        fclose(file);
    } else {
        TraceLog(LOG_ERROR, "Failed to read file!");
    }

    //Render loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        float time = GetTime();
        
        //Text flickers with sine wave alpha
        float speed = 1.0f; 
        float alphaR = 0.3f + 0.7f * sin(time * speed+PI);
        float alphaL = 0.3f + 0.7f * sin(time * speed);

        Color blinkLeft = Fade(DARKBLUE, alphaL);
        Color blinkRight = Fade(DARKGREEN, alphaR);
        Color titleColor = Fade(RED, 0.8f + 0.2f * sin(time * 2.0f));

        //Write the title
        DrawText("Hello, BABY!", 250, 20, 60, titleColor);

        //Layout parameters
        int startX_Left = 30;   // basic left X
        int startX_Right = 420; // basic right X
        int startY_Base = 70;  // basic Y

        int fontSize = 45;  // Font size
        int rowHeight = 50; // Line height
        int groupGap = 100; // Group spacing

        for (int round = 0; round < 10; round++) {
            int currentY = startY_Base + (round * groupGap);

            if (lineCount > 0) DrawText(lines[0], startX_Left, currentY, fontSize, blinkLeft);
            if (lineCount > 1) DrawText(lines[1], startX_Left, currentY + rowHeight, fontSize, blinkLeft);

            if (lineCount > 2) DrawText(lines[2], startX_Right, currentY, fontSize, blinkRight);
            if (lineCount > 3) DrawText(lines[3], startX_Right, currentY + rowHeight, fontSize, blinkRight);
        }

        EndDrawing();
    }

    //Clean up resources
    CloseWindow();
    
    return 0;
}
