#define PLATFORM_DESKTOP
// Prevent collisions between Win32 API and raylib symbols by renaming Win32
// identifiers before pulling in <windows.h>.
#define CloseWindow Win32_CloseWindow
#define ShowCursor Win32_ShowCursor
#define Rectangle Win32_Rectangle

#define WIN32_LEAN_AND_MEAN
#define NOGDI             // omit GDI declarations (includes Rectangle)
#include <windows.h>

// undo renames so raylib gets its normal names
#undef CloseWindow
#undef ShowCursor
#undef Rectangle

// Windows headers also define macros for some common names, e.g. LoadImage,
// DrawText, DrawTextEx, which would expand raylib declarations to their A/W
// variants and cause conflicting type errors.  Undefine them too.
#undef LoadImage
#undef DrawText
#undef DrawTextEx

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// raylib can now be included safely; its CloseWindow/ShowCursor definitions
// won't be shadowed by the Win32 ones.
#include <raylib.h>

//Define the resource ID
#define IDR_MUSIC1 101 

// log file handle used by custom TraceLog callback
static FILE *g_logFile = NULL;

// callback that forwards raylib log messages into a file
static void FileLogCallback(int msgType, const char *text, va_list args) {
    if (!g_logFile) return;
    vfprintf(g_logFile, text, args);
    fprintf(g_logFile, "\n");
    fflush(g_logFile);
}

//Extract files from the resources to the temporary path
bool ExtractResourceToFile(int resourceId, const char* tempPath) {
    // Resource stored as RCDATA in resource.rc
    HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(resourceId), RT_RCDATA);
    if (!hRes) return false;

    HGLOBAL hResLoad = LoadResource(NULL, hRes);
    if (!hResLoad) return false;

    void* resData = LockResource(hResLoad);
    DWORD resSize = SizeofResource(NULL, hRes);

    FILE* file = fopen(tempPath, "wb");
    if (!file) return false;

    fwrite(resData, 1, resSize, file);
    fclose(file);
    
    return true;
}

int main() {
    // open log file and register callback
    g_logFile = fopen("run_trace.log", "w");
    if (g_logFile) SetTraceLogCallback(FileLogCallback);

    // Set up the window
    InitWindow(900, 1000, "FUCK YOU, BITCH!");
    SetTargetFPS(60);
    
    //Initialization music resource
    InitAudioDevice();
    Music music = {0};
    bool musicLoaded = false;
    float musicDuration = 0.0f;

    // Load music from the resources
    char tempPath[MAX_PATH];
    if (GetTempPathA(MAX_PATH, tempPath) == 0) {
        TraceLog(LOG_ERROR, "GetTempPath failed, GetLastError=%lu", GetLastError());
    } else {
        strcat(tempPath, "temp_raylib_music.mp3");

            // Diagnostic: check resource presence with multiple type names
        HRSRC _hRes_rcdata = FindResource(NULL, MAKEINTRESOURCE(IDR_MUSIC1), RT_RCDATA);
        HRSRC _hRes_mp3 = FindResource(NULL, MAKEINTRESOURCE(IDR_MUSIC1), "MP3");
        HRSRC _hRes_stringR = FindResource(NULL, MAKEINTRESOURCE(IDR_MUSIC1), TEXT("RCDATA"));
        TraceLog(LOG_INFO, "FindResource(RT_RCDATA) -> %p", (void*)_hRes_rcdata);
        TraceLog(LOG_INFO, "FindResource(""MP3"") -> %p", (void*)_hRes_mp3);
        TraceLog(LOG_INFO, "FindResource(""RCDATA"" as TEXT) -> %p", (void*)_hRes_stringR);

        if (ExtractResourceToFile(IDR_MUSIC1, tempPath)) {
            TraceLog(LOG_INFO, "Resource extracted to: %s", tempPath);

            FILE *tf = fopen(tempPath, "rb");
            if (tf) {
                fseek(tf, 0, SEEK_END);
                long fsz = ftell(tf);
                fclose(tf);
                TraceLog(LOG_INFO, "Extracted file size: %ld bytes", fsz);

                if (fsz > 0) {
                    // Try load and check duration (raylib returns 0 for unknown/failed loads)
                    music = LoadMusicStream(tempPath);
                    musicDuration = GetMusicTimeLength(music);
                    if (musicDuration > 0.0f) {
                        PlayMusicStream(music);
                        musicLoaded = true;
                        TraceLog(LOG_INFO, "Music loaded, duration: %.2f seconds", musicDuration);
                    } else {
                        TraceLog(LOG_ERROR, "LoadMusicStream failed or unsupported format (duration=0). Consider using OGG/WAV or enabling MP3 support in raylib.");
                    }
                } else {
                    TraceLog(LOG_ERROR, "Extracted file is empty: %s", tempPath);
                }
            } else {
                TraceLog(LOG_ERROR, "Failed to open extracted file: %s", tempPath);
            }
        } else {
            TraceLog(LOG_ERROR, "ExtractResourceToFile failed, GetLastError=%lu", GetLastError());
            // Fallback: try loading from working directory to check MP3 support
            const char *localFile = "love_song.mp3";
            TraceLog(LOG_INFO, "Attempting fallback load from: %s", localFile);
            music = LoadMusicStream(localFile);
            musicDuration = GetMusicTimeLength(music);
            if (musicDuration > 0.0f) {
                PlayMusicStream(music);
                musicLoaded = true;
                TraceLog(LOG_INFO, "Fallback music loaded from disk, duration: %.2f seconds", musicDuration);
            } else {
                TraceLog(LOG_ERROR, "Fallback LoadMusicStream failed or unsupported format (duration=0).\nConsider embedding as RCDATA and/or using OGG/WAV.");
            }
        }
    }

    //Create and write to the file
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

    //Read the file
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
    }

    //Render loop
    while (!WindowShouldClose()) {
        //Check if the music has finished playing
        if (musicLoaded) {
            UpdateMusicStream(music);
            float currentTime = GetMusicTimePlayed(music);
            if (currentTime >= musicDuration - 0.5f) {
                TraceLog(LOG_INFO, "Music finished! Closing window...");
            }
            
            if (currentTime >= musicDuration) {
                 break; 
            }
        }

        //Create map
        BeginDrawing();
        ClearBackground(RAYWHITE);

        float time = GetTime();// Get the current time (in seconds)
        
        float speed = 3.0f; // Adjust this value to change the flicker speed
        float alphaR = 0.3f + 0.7f * sin(time * speed + PI); 
        float alphaL = 0.3f + 0.7f * sin(time * speed); 

        int startX_Left = 40;
        int startX_Right = 420;
        int startY_Base = 60;
        
        int fontSize = 45;          // Font size
        int rowHeight = 50;         // Line height
        int groupGap = 100;         // Group spacing

        // Define the base color
        Color leftColor = SKYBLUE;
        Color rightColor = GREEN;

        // Apply the color after it has flickered
        Color blinkLeft = Fade(leftColor, alphaL);
        Color blinkRight = Fade(rightColor, alphaR);

        // Create a dynamic main title
        char titleMsg[100];
        if (musicLoaded) {
            float remaining = musicDuration - GetMusicTimePlayed(music);
            if (remaining < 0) remaining = 0;
            sprintf(titleMsg, "Hello, BABY! (%.1fs left)", remaining);
            DrawText(titleMsg, 180, 20, 50, Fade(RED, 0.8f + 0.2f * sin(time * 2.0f)));
            
            DrawText("Music Playing", 180, 80, 24, DARKPURPLE);
        } else {
            DrawText("Hello, BABY!", 220, 20, 60, RED);
            DrawText("Music Load Failed", 200, 90, 24, RED);
        }

        //Draw the text
        for (int round = 0; round < 10; round++) {
            int currentY = startY_Base + (round * groupGap);
            if (lineCount > 0) {DrawText(lines[0], startX_Left, currentY, fontSize, blinkLeft);}
            if (lineCount > 1) {DrawText(lines[1], startX_Left, currentY + rowHeight, fontSize, blinkLeft);}
            if (lineCount > 2) {DrawText(lines[2], startX_Right, currentY, fontSize, blinkRight);}
            if (lineCount > 3) {DrawText(lines[3], startX_Right, currentY + rowHeight, fontSize, blinkRight);}
        }

        //Display the progress bar
        if (musicLoaded) {
            float progress = GetMusicTimePlayed(music) / musicDuration;
            if (progress > 1.0f) progress = 1.0f;
            DrawRectangle(250, 120, progress * 350, 10, MAROON);
            DrawRectangleLines(250, 120, 350, 10, DARKGRAY);
        }

        DrawFPS(20, GetScreenHeight() - 40);
        EndDrawing();
    }

    //Clean up resources
    TraceLog(LOG_INFO, "Program ending gracefully.");
    if (g_logFile) {
        fclose(g_logFile);
        g_logFile = NULL;
    }
    if (musicLoaded) {
        StopMusicStream(music);
        UnloadMusicStream(music);
        DeleteFile(tempPath); 
    }
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
