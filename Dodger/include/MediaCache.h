#ifndef MEDIACACHE_H
#define MEDIACACHE_H

#include "SDL.h"
#include <string>
#include "ImageCache.h"
#include "FontCache.h"
#include "TextCache.h"

class MediaCache
{
	private:
		const short mScrWidth, mScrHeight;
		SDL_Window* window;
		SDL_Renderer* ren;
		SDL_Color textColor;

		ImageCache imgCache;
		FontCache fontCache;
		TextCache txtCache;

		MediaCache &operator=(const MediaCache&);
		MediaCache(const MediaCache&);

	public:
		MediaCache();
		~MediaCache();

		std::shared_ptr<GameTexture> getImage(const std::string file);
		TTF_Font* getFont(const int size);
		std::shared_ptr<GameTexture> getText(const std::string message, TTF_Font* font, const SDL_Color color);

		void renderTexture(std::shared_ptr<GameTexture> tex, const int x, const int y);
		void drawRectangle(SDL_Rect rect, const SDL_Color color);

		void clearScreen();
		void updateScreen() { SDL_RenderPresent(ren); }

		short scrWidth() const { return mScrWidth; }
		short scrHeight() const { return mScrHeight; }
		int centreX(int gtWidth) const;
		int centreY(int gtHeight) const;
		SDL_Color getTextColor();	
};

#endif