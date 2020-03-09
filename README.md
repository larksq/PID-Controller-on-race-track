# CarND-Controls-PID
This is a project from Self-Driving Car Engineer Nanodegree Program.

---

## PID parameters tuning

There are two version of fine-tuned parameters:
- Version 1: P = 0.10; I = 0.0004; D = 0.85
- Version 2: P = 0.19; I = 0.0001; D = 5.00

The first version will drive smooth without many overshoots. But will get very close to the edge when passing the sharp turn. So I give more P value and decrease I value (because smaller I value did not bring additional steady error). And I also increase the D value to decrease overshoots. The second version will still overshoots once the car need to make a sharp turn. The P and I will response more rapid but yield a stumbling left and right driving style after passing the sharp turn.

There is another interesting thing I noticed which is the performance is also related with the response speed of the system. When recording a video of the simulator, the script will response slower than normal and the system will also response slower when making sharp turns.

## Speed Control and experiment

I also built a simple PID controller for speed control. You can change the value of TARGET_SPEED to try to race at different speed. 

I found out that a speed which is too slow will also hurt the overall performance. A low enough speed might decrease the response since the car needs enough momentum with the turning to correct the error. A target speed of 25 or 35 works fine for my laptop.

I also gave the speed a penalty when the error is huge so that the car can have more time to response. Yet this only works in some specific cases (when the error is increasing gradually). I kept the penalty between 0-1 so that small error did not blow the speed off.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

Fellow students have put together a guide to Windows set-up for the project [here](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) if the environment you have set up for the Sensor Fusion projects does not work for this project. There's also an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

