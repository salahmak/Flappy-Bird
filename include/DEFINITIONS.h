#ifndef DEFINITIONS_H
#define DEFINITIONS_H


#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 640

#define FRAMERATE 60.0f

#define SPLASH_STATE_SHOW_TIME 0.1f
#define SPLASH_SCENE_IMAGE_PATH "assets/res/splash_bg.png"

#define MAIN_MENU_BACKGROUND_PATH "assets/res/sky.png"
#define GAME_TITLE_PATH "assets/res/title.png"
#define PLAY_BUTTON_PATH "assets/res/play_btn.png"



#define GAME_OVER "assets/res/game-over.png"
#define GAME_OVER_BODY "assets/res/game-over-body.png"


#define PIPE_DOWN_PATH "assets/res/PipeDown.png"
#define PIPE_UP_PATH "assets/res/PipeUp.png"


#define PIPE_SPEED 200.0f
#define PIPE_SPAWN_FREQ 1.3f


#define LAND_PATH "assets/res/land.png"


#define BIRD_FRAME_1_PATH "assets/res/bird-01.png"
#define BIRD_FRAME_2_PATH "assets/res/bird-02.png"
#define BIRD_FRAME_3_PATH "assets/res/bird-03.png"
#define BIRD_FRAME_4_PATH "assets/res/bird-04.png"




#define BIRD_ANIMATION_TIME 0.4f

//todo Convert this to an enum
#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define GRAVITY 350.0f
#define FLYING_SPEED 200.0f
#define FLYING_DURATION 0.25f

#define ROTATION_SPEED 100.0f

enum GameStates 
{
	ready,
	playing,
	gameOver
};


#endif // DEFINITIONS_H
