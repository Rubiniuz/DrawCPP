# DrawCPP
Drawing app using SFML2 as render engine

Goal is to make a minimalistic drawing app that uses 3 coding design patterns.

All patterns can be found on https://refactoring.guru/

# Design Patterns

Singleton :

    The Singleton pattern will be used as a manager. It will manage all drawing operations
    DrawManager will be the name of this Singleton.

Strategy :

    A Strategy pattern will be used for drawing operations.
    The head Interface will be a Drawable.
    We will add 2-4 Drawables (dot, line, rectangle, ellipse)
    The 'Context' that delegates the Drawable Strategies will be the DrawManager

Command :

    The Command pattern allows requests to be turned into objects.
    This would allow drawing, erasing and possibly cutting the drawing
    Example: "A draw rectangle request would become a Drawable which will be drawn by the DrawManager"

Unknown Pattern : 

    I forgot this pattern. the pattern that allows for a list of instructions or commands.
    Adding these on top of eachother gives you the ablility to undo and redo.
    this sort of is a part of the command pattern

# Application

    Not following the first design.
    We are NOT going to use predefined drawables from sfml. 
    This to not have this huge mess of render textures and layers.
    We will manualy calculate and draw the pixels onto one texture which will be rendered