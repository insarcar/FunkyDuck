#pragma once

#include<JuceHeader.h>

class MyLookAndFeel : public LookAndFeel_V4
{
public:
	MyLookAndFeel() 
	{
		setColour(Slider::thumbColourId, Colours::red);
	};

	void drawRotarySlider(Graphics& g, int x, int y, int width, int heigth,
		float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override 
	{
		//temp variables
		auto radius = (jmin(width * 0.5f, heigth * 0.5f) - 4.0f) * 0.85f;
		auto centreX = x + width * 0.5f;
		auto centreY = y + heigth * 0.5f;
		auto rx = centreX - radius;
		auto ry = centreY - radius;
		auto rw = radius * 2.0f;

		Colour brightColour = Colour(0xffdcc38c);
		Colour darkColour = Colour(0xffce6632);
		//rotary body
		g.setGradientFill(ColourGradient(brightColour, rx, ry, darkColour.brighter(0.05f), rx, ry + rw, false));
		g.fillEllipse(rx, ry, rw, rw);

		//rotary bound
		g.setGradientFill(ColourGradient(brightColour.brighter(0.2f), rx, ry, darkColour.brighter(0.05f), rx, ry + rw, false));
		g.drawEllipse(rx, ry, rw, rw, 1.5f);

		//pointer shape
		Path p;
		auto pointerLength = radius * 0.33f;
		auto pointerThickness = 2.0f;
		p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);

		//draw pointer in a current position, applico la rotazione al rettangolo
		auto angle = rotaryStartAngle + sliderPosProportional * (rotaryEndAngle - rotaryStartAngle);
		p.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));
		g.setGradientFill(ColourGradient(Colours::white, rx, ry, Colours::white.darker(0.2f), rx, ry + rw, false));
		g.fillPath(p);

		//draw ticks
		Path originalTickShape, temp;
		auto numTicks = (slider.getInterval() < 0.01f) ? 13 : 11;
		auto tickSize = 2.0f;
		originalTickShape.addEllipse(-tickSize * 0.5f, -radius * 1.17f, tickSize, tickSize);
		g.setColour(Colours::white);
		for (int i = 0; i < numTicks; ++i)
		{
			temp = originalTickShape;
			float angle = rotaryStartAngle + pow(i / (numTicks - 1.0f), slider.getSkewFactor()) * (rotaryEndAngle - rotaryStartAngle);
			temp.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));
			g.fillPath(temp);
		}
	};

	void drawTickBox(Graphics& g, Component& b, float x, float y, float w, float h, bool ticked, 
		bool isEnabled,bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
	{
		//auto isDownOrDragging = b.isEnabled() && (b.isMouseOverOrDragging() || b.isMouseButtonDown());
		//toggle off
		w *= 2.5f;
		h *= 2.5f;
		y -= 13.0f;
		x += 60.0f;
		auto radius = jmin(w * 0.5f, h * 0.5f) * 1.2f;
		auto centreX = x + w * 0.5f;
		auto centreY = y + h * 0.5f;
		auto rx = centreX - radius;
		auto ry = centreY - radius;
		auto rw = radius * 2.0f;

		Colour brightColour = Colour(0xfff0dbea);
		Colour darkColour = Colour(0xffedd3da);

		g.setColour(Colours::white);
		g.fillEllipse(rx, ry, rw, rw);

		g.setGradientFill(ColourGradient(brightColour.brighter(0.2f), rx, ry, darkColour.brighter(0.2f), rx, ry + rw, false));
		g.drawEllipse(rx + 1.0f, ry + 1.0f, rw + 1.0f, rw + 1.0f, 1.5f);

		//led off
		auto w_led = 10.0f;
		auto h_led = 10.0f;
		auto r_led = jmin(w_led * 0.5f, h_led * 0.5f);
		auto x_led = x + 55.0f;
		auto y_led = centreY - 5.0f;
		auto centreX_led = x_led + w_led * 0.5f;
		auto centreY_led = y_led + h_led * 0.5f;
		auto rx_led = centreX_led - r_led;
		auto ry_led = centreY_led - r_led;
		auto rw_led = r_led * 2.0f;

		Colour ledOffDark = Colours::black;
		Colour ledOffBright = Colours::transparentBlack;

		g.setGradientFill(ColourGradient(ledOffDark, centreX_led, centreY_led, ledOffBright, rx_led, ry_led, true));
		g.fillEllipse(rx_led, ry_led, rw_led, rw_led);

		if(ticked)
		{
			//led on
			Colour ledOnBright = Colours::white;
			Colour ledOnLight = Colours::orangered;
			Colour background = Colour(0xfff1d4d4);

			g.setGradientFill(ColourGradient(ledOnBright, centreX_led, centreY_led, ledOnLight, rx_led, ry_led, true));
			g.fillEllipse(rx_led, ry_led, rw_led, rw_led);

			g.setGradientFill(ColourGradient(ledOnLight, centreX_led, centreY_led, background, rx_led , ry_led , true));
			g.drawEllipse(rx_led, ry_led, rw_led, rw_led, 3.0f);

			//toggle on
			g.setGradientFill(ColourGradient(ledOffBright.darker(0.1f), centreX, centreY, brightColour.darker(0.1f), rx, ry + rw, true));
			g.fillEllipse(rx, ry, rw, rw);
			
			g.setGradientFill(ColourGradient(brightColour.darker(0.2f), rx, ry, darkColour.darker(0.2f), rx, ry + rw, false));
			g.drawEllipse(rx + 1.0f, ry + 1.0f, rw + 1.0f, rw + 1.0f, 1.5f);

		}
	};

};