sh2d [![Build Status](https://travis-ci.org/posva/sh2d.png?branch=master)](https://travis-ci.org/posva/sh2d)
====
2D Graphics wannabe for the console

## Intro
The main purpose of this lib is to display graphics n the console handling all the resizing and color conversion and if I'm able to, to handle the sprites and view too and therefore be a 2D engine (quite simple thought)

## Compilation
To compile the project I suggest you to clone this repo: [configure-script](https://github.com/posva/configure-script) at your home. If you don't the `./configure` will download a copy of the script. To compile and test the project do:
```
cmake .
make
make test
```

## Usages
* `catimg`: Its the C version of my script [catimg](https://github.com/posva/catimg) and therefore almost instant depending on the picture size

![example](http://i.imgur.com/rwwsjMn.png "yoshi")]

* 2D Engine: This is what I aim for

## Documentation
I'm using `doxygen` for the doc but there is not a main page yet. If you want to build it:
```
doxygen Doxyfile
```

## Dependencies
There are **no** dependencies for the moment and I'l try to keep it this way

## Credits
I use `stb_image` by [Sean Barrett](http://nothings.org/) to load images.

## Licence
It'll surely be GPL GNU v3. I'll decide this later and put the licence when the lib is functional :smile:

