# Lets-edit-photos
A dynamic image processing system built with C++.
# Kets Edit Photos 📸✨

## Dynamic Image Processing in C++

### Overview 🎉
Welcome to **Kets Edit Photos** – your quirky, fun-filled tool for basic image processing! Built in C++ using dynamic 2D arrays, this project lets you flip, invert, and crop images with a twist of humor. Whether you want to mirror your selfie, create a dramatic negative, or crop out that photobombing friend, this program's got you covered!

### Features 🌟
- **Dynamic 2D Array Magic:**  
  Allocate and manage your image pixels on-the-fly, like a wizard with digital brushes.
  
- **Image Flipping:**  
  Flip your image horizontally to get that cool mirror effect. 🔄

- **Negative Conversion:**  
  Transform your image into a negative by subtracting each pixel value from 255 – it’s like looking at your photo in reverse time! ⏪

- **Cropping:**  
  Resize your image by specifying new dimensions (just remember, smaller than the original!). ✂️

- **User-Friendly Interaction:**  
  A simple console menu that’s so fun and easy, even your grandma might join the party! 👵

- **Memory Management:**  
  Clean up after yourself – the program deallocates memory like a pro, keeping your system as neat as your workspace. 🧹

### How It Works 🛠️
1. **Input:**  
   Enter the image dimensions (height and width in pixels) and populate the 2D array with your chosen pixel values (0-255).

2. **Process:**  
   - **Flip:** The program mirrors the image by swapping pixel rows.
   - **Negative:** It converts the image to its negative by subtracting pixel values from 255.
   - **Crop:** Resize the image by cropping it based on user-defined dimensions.

3. **Display:**  
   Enjoy side-by-side views of your original and processed images right in your console.

4. **Cleanup:**  
   Dynamically allocated memory is freed up at the end – because good things (and good code) always clean up after themselves!

### Getting Started 🚀
#### Requirements:
- **Compiler:**  
  A C++ compiler that supports C++11 or later (e.g., g++, Visual Studio).

- **Libraries:**  
  Standard libraries (`iostream`, `iomanip`, and `conio.h` for that retro console vibe).

