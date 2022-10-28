# Sketch Track
Sketch Track is an interactive openFrameworks application. The application reads handdrawn image with any type of line and moves a white circle on the line using it as a path.

## Demo
![](https://github.com/jorjepadre/sketchTrack/blob/master/bin/data/demo.gif)

## Methodology
The main technique used in the implementation is the "Canny Edge Detection". In the *bin/data* folder, images with the lines of different shapes are stored. This shows that Canny Edge Detection methodology can deal with almost any kind of edges and detects them with high efficiency.

### Implementation
On the first step, the image is loaded and read by the program. After that, the image matrix is generated. On this matrix we produce the Gaussian Blur to reduce the noise and filter it, and after that, we do the Canny Edge Detection. This leaves the matrix with the edges already detected.

Then, we store all the edge pixels in array, and in each iteration we draw a circle on one edge pixel on top of the image. This makes the cirle smoothly follow the line.

Another functionality, is interactive low threshold controller that we put on top of gui. This helps us manipulate the edge detection of Canny. Increasing the low threshold will remove most of the candidates for becoming an edge and lowering the threshold will make more edges, even those that are not edges (maybe because of the noise).
