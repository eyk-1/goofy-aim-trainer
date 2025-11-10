#include "Button.h"

Button::Button(const char* imagePath, Vector2 imagePosition,float scale)
{
	Image image = LoadImage(imagePath);
	int width = image.width*scale;
	int height = image.height * scale;
	ImageResize(&image, width, height);
	texture = LoadTextureFromImage(image);
	position = imagePosition;
}

Button::~Button()
{
	UnloadTexture(texture);
}

void Button::Draw()
{
	DrawTextureV(texture, position, WHITE);
}

bool Button::isPressed()
{
	Rectangle rec = {position.x,position.y,(float)texture.width,(float)texture.height};
	return (CheckCollisionPointRec(GetMousePosition(), rec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}
