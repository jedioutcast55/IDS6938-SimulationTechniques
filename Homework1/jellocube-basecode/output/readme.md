This directory contains the collection of images the jello program outputs.

To create a movie, double click "make_me_a_movie.bat"
This will run ffmpeg on whatever is in your folder.
(remember to clear out the pngs first or run it on another folder)


You have two options: Open the bat file and modify the script yourself

or

You could also  Hold shift + right click in the explorer window 
"Open command window here"
and open a command terminal

Then you can use 
ffmpeg\ffmpeg.exe -framerate 24 -i %04d.png jello_output.mp4
command directly



The command is broken down as follows:
ffmpeg\ffmpeg.exe  - location of the exe file, it is in the ffmpeg folder in this directory.
-framerate   24    usually good for movies, but you can adjust this to slow it down or speed it up
%04d.png    -  there are 4 numbers in from of the png image 0001.png
jello_output.mp4  - name of file


there are more commands you can google for that control the bitrate, quality, etc