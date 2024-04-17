/*----------------------------------------------------------------------------------*/
//File name   :   CS112_A3_Part1_25_20231208_20231071_20231189.cpp
//Description :   This program can load images and apply different filters to them
//Names       :   Youssef Ahmed Mahmoud Mohamed Elebiary    -    20231208
//                Zainab Mostafa Mohammad Mahmoud Ali       -    20231071
//                Nagham Wael Mohamed                       -    20231189
//Who did what:   Youssef   ->   Invert Filter and menu
//                Nagham    ->   Black and White and flip
//                Zainab    ->   Lighten/Darken and grayscale
/*----------------------------------------------------------------------------------*/

#include <iostream>
#include "Image_Class.h"
#include <vector>
#include <iomanip>
#include <cmath>

#define ll long long

using namespace std;

//Function Prototypes
bool isValidExtension(string&);
bool isValidFile(string&);
void invert_image(Image&);
void black_white(Image&);
void flip_vertically(Image&);
void flip_horizontally(Image&);
void GrayScaling(Image&);
void Lighten(Image&);
void Darken(Image&);
Image rotate(Image);
void add_frame(Image&, int, int, int);
vector<vector<vector<ll>>> prefix_sum(Image);
void blur(Image&);
void cropImage(Image&, int, int, int, int);
void resizeImage(Image&);
void dark_red(Image&);
void infrared(Image&);
void purple(Image&);
void sunlight(Image&);
void tv(Image&);
void slytherin(Image&);
void merge(Image&, Image);
void oil(Image&);
void skew(Image&);
void edge_detection(Image&);
void autosave(Image);


bool autosave_flag = false;


int main() {
    //Initializing the variables
    string file_name;
    int choice, save_type, s, f, degree, c_mode;
    bool isSaved = true;
    //Welcome menu
    cout << "Welcome to the BabyPhotoShop program\n" << "This program allows you to apply filters to images\nAuto save is disabled by default\n\n";
    //Getting the file name
    cout << "Enter the file name and its extension (PNG/JPG/BMP/TGA): ";
    getline(cin, file_name);
    //Handling invalid filenames
    while (!isValidFile(file_name)) {
        cout << "\nInvalid Input\n";
        cout << "Enter the file name and its extension (PNG/JPG/BMP/TGA): ";
        getline(cin, file_name);
    }
    //Loading the image
    Image image(file_name);
    //Program loop
    while (true) {
        //Getting which filter to apply to the image
        cout << "\nMain Menu\n";
        cout << setw(25) << left << "1) Grayscale" << right << "2) Black and White\n" << setw(25) << left << "3) Invert Image" << right << "4) Flip\n" << setw(25) << left << "5) Rotate" << right << "6) Light and Dark\n" << setw(25) << left << "7) Skew" << right << "8) Frame\n" <<
                setw(25) << left << "9) Blur" << right << "10) Crop\n" << setw(25) << left << "11) Resize" << right << "12) Dark Red\n" << setw(25) << left << "13) Infrared" << right << "14) Oil Painting\n"  << setw(25) << left << "15) Purple" << right << "16) Sunlight\n" <<
                setw(25) << left << "17) TV" << right << "18) Slytherin\n" << setw(25) << left << "19) Detect Edges" << right << "20) Merge\n" << setw(25) << left << "21) Load Image" << right << "22) Save Image\n" << setw(25) << left << "23) Autosave" << right << "24) Exit\n";
        cout << "Choice: ";
        cin >> choice;
        //Handling invalid input
        while (cin.fail() || !(1 <= choice && choice <= 24)) {
            cout << "\nInvalid Input\n";
            cout << "\nMain Menu\n";
            cout << setw(25) << left << "1) Grayscale" << right << "2) Black and White\n" << setw(25) << left << "3) Invert Image" << right << "4) Flip\n" << setw(25) << left << "5) Rotate" << right << "6) Light and Dark\n" << setw(25) << left << "7) Skew" << right << "8) Frame\n" <<
                    setw(25) << left << "9) Blur" << right << "10) Crop\n" << setw(25) << left << "11) Resize" << right << "12) Dark Red\n" << setw(25) << left << "13) Infrared" << right << "14) Oil Painting\n"  << setw(25) << left << "15) Purple" << right << "16) Sunlight\n" <<
                    setw(25) << left << "17) TV" << right << "18) Slytherin\n" << setw(25) << left << "19) Detect Edges" << right << "20) Merge\n" << setw(25) << left << "21) Load Image" << right << "22) Save Image\n" << setw(25) << left << "23) Autosave" << right << "24) Exit\n";
            cout << "Choice: ";
            cin >> choice;
        }
        //Applying the filters as entered
        if (choice == 1) {                  //Grayscale Conversion
            GrayScaling(image);
            isSaved = false;
        } else if (choice == 2) {           //Black and White
            black_white(image);
            isSaved = false;
        } else if (choice == 3) {           //Invert Image
            invert_image(image);
            isSaved = false;
        } else if (choice == 4) {           //Flip
            //Getting flip direction
            cout << "\nSelect the flip direction\n1) Flip Vertically\n2) Flip Horizontally\nDirection: ";
            cin >> f;
            //Handling invalid input
            while (cin.fail() || !(1 <= f && f <= 2)) {
                cout << "\nInvalid Input\n";
                cout << "\nSelect the flip direction\n1) Flip Vertically\n2) Flip Horizontally\nDirection: ";
                cin >> f;
            }
            //Flipping according to choice
            if (f == 1) {                   //Vertically
                flip_vertically(image);
            } else if (f == 2) {            //Horizontally
                flip_horizontally(image);
            }
            isSaved = false;
        } else if (choice == 5) {           //Rotate
            cout << "Enter the degree of rotation (clockwise)\n";           //Getting the degree of rotation
            cout << "1) 90\n2) 180\n3) 270\nDegree: ";
            cin >> degree;
            //Handling invalid input
            while (cin.fail() || !(1 <= degree && degree <= 3)) {
                cout << "Enter the degree of rotation (clockwise)\n";
                cout << "1) 90\n2) 180\n3) 270\nDegree: ";
                cin >> degree;
            }
            if (degree == 1) {                  //90 degrees rotation
                for (int i = 0; i < 3; ++i) {
                    image = rotate(image);
                }
            } else if (degree == 2) {           //180 degrees rotation
                for (int i = 0; i < 2; ++i) {
                    image = rotate(image);
                }
            } else if (degree == 3) {           //270 degrees rotation
                image = rotate(image);
            }
            isSaved = false;
        } else if (choice == 6) {           //Light and Dark
            int bright;
            cout << "What do you want to do?\n";
            cout << "1) Lighten\n2) Darken\n";
            cout << "Choice: ";
            cin >> bright;
            //Handling Invalid Input
            while (cin.fail() || !(1 <= bright && bright <= 2)) {
                cout << "\nInvalid Input\n";
                cout << "1) Lighten\n2) Darken\n";
                cout << "Choice: ";
                cin >> bright;
            }
            (bright == 1) ? Lighten(image) : Darken(image);
            isSaved = false;
        } else if (choice == 7) {           //Skew
            skew(image);
            isSaved = false;
        } else if (choice == 8) {           //Add a Frame
            int R, G, B, color;
            //Getting the color codes
            cout << "Choose the color of the frame\n";
            cout << setw(15) << left << "1) Red" << right << "2) Green\n" <<
                    setw(15) << left << "3) Blue" << right << "4) Purple\n" <<
                    setw(15) << left << "5) Yellow" << right << "6) Cyan\n" <<
                    setw(15) << left << "7) Black" << right << "8) White\n";
            cout << "Color: ";
            cin >> color;
            while (cin.fail() || !(1 <= color && color <= 8)) {
                cout << "\nInvalid Input\n";
                cout << setw(15) << left << "1) Red" << right << "2) Green\n" <<
                        setw(15) << left << "3) Blue" << right << "4) Purple\n" <<
                        setw(15) << left << "5) Yellow" << right << "6) Cyan\n" <<
                        setw(15) << left << "7) Black" << right << "8) White\n";
                cout << "Color: ";
                cin >> color;
            }
            if (color == 1) {
                R = 255;
                G = 0;
                B = 0;
            } else if (color == 2) {
                R = 0;
                G = 255;
                B = 0;
            } else if (color == 3) {
                R = 0;
                G = 0;
                B = 255;
            } else if (color == 4) {
                R = 168;
                G = 5;
                B = 250;
            } else if (color == 5) {
                R = 255;
                G = 255;
                B = 0;
            } else if (color == 6) {
                R = 16;
                G = 163;
                B = 222;
            } else if (color == 7) {
                R = G = B = 0;
            } else if (color == 8) {
                R = G = B = 255;
            }
            add_frame(image, R, G, B);
            isSaved = false;
        } else if (choice == 9) {           //Blur
            blur(image);
            isSaved = false;
        } else if (choice == 10) {          //Crop
            int firstCorner, secondCorner, cropWidth, cropHeight;
            cout << "Enter the first corner: ";
            cin >> firstCorner;
            while (cin.fail() || !(0 <= firstCorner && firstCorner <= image.width)) {
                cout << "\nInvalid Starting Point\n";
                cout << "Enter the first corner: ";
                cin >> firstCorner;
            }
            cout << "Enter the second corner: ";
            cin >> secondCorner;
            while (cin.fail() || !(0 <= secondCorner && secondCorner <= image.height)) {
                cout << "\nInvalid Starting Point\n";
                cout << "Enter the second corner: ";
                cin >> secondCorner;
            }
            cout << "Enter the first dimension(width): ";
            cin >> cropWidth;
            while (cin.fail() || !(0 <= cropWidth && cropWidth <= image.width)) {
                cout << "\nInvalid Starting Point\n";
                cout << "Enter the first dimension(width): ";
                cin >> cropWidth;
            }
            cout << "Enter the second dimension(height): ";
            cin >> cropHeight;
            while (cin.fail() || !(0 <= cropHeight && cropHeight <= image.height)) {
                cout << "\nInvalid Starting Point\n";
                cout << "Enter the second dimension(height): ";
                cin >> cropHeight;
            }
            cropImage(image, firstCorner, secondCorner, cropWidth, cropHeight);
            isSaved = false;
        } else if (choice == 11) {          //Resize
            resizeImage(image);
            isSaved = false;
        } else if (choice == 12) {          //Dark Red
            dark_red(image);
            isSaved = false;
        } else if (choice == 13) {          //Infrared
            infrared(image);
            isSaved = false;
        } else if (choice == 14) {          //Oil
            oil(image);
            isSaved = false;
        } else if (choice == 15) {          //Purple
            purple(image);
            isSaved = false;
        } else if (choice == 16) {          //Sunlight
            sunlight(image);
            isSaved = false;
        } else if (choice == 17) {          //TV
            tv(image);
            isSaved = false;
        } else if (choice == 18) {          //Slytherin
            slytherin(image);
        } else if (choice == 19) {          //Detect Edges
            edge_detection(image);
            isSaved = false;
        } else if (choice == 20) {          //Merge
            string file2;
            cin.ignore();
            cout << "Enter the second image's name: ";
            getline(cin, file2);
            while (!isValidFile(file_name)) {
                cout << "\nInvalid Input\n";
                cout << "Enter the file name and its extension (PNG/JPG/BMP/TGA): ";
                getline(cin, file_name);
            }
            Image img2(file2);
            merge(image, img2);
            isSaved = false;
        } else if (choice == 21) {          //Load Another Image
            //Getting the file name
            cin.ignore();
            cout << "Enter the file name and its extension (PNG/JPG/BMP/TGA): ";
            getline(cin, file_name);
            //Handling invalid filenames
            while (!isValidFile(file_name)) {
                cout << "Enter the file name and its extension (PNG/JPG/BMP/TGA): ";
                getline(cin, file_name);
            }
            //Loading the other image
            image.loadNewImage(file_name);
            isSaved = true;
        } else if (choice == 22) {           //Save
            //Getting how to save the image
            cout << "\nSelect how to save the image\n";
            cout << "1) Replace the old image\n2) Save as a new image\n";
            cout << "Type: ";
            cin >> save_type;
            //Handling invalid input
            while (cin.fail() || !(1 <= save_type && save_type <= 2)) {
                cout << "\nInvalid Input\n";
                cout << "\nSelect how to save the image\n";
                cout << "1) Replace the old image\n2) Save as a new image\n";
                cout << "Type: ";
                cin >> save_type;
            }
            if (save_type == 1) {           //Replace old image
                //Saving the image
                image.saveImage(file_name);
                cout << "Saved Successfully\n";
                isSaved = true;
            } else if (save_type == 2) {    //Save as a new image
                //Getting the name of the new image
                cout << "Enter the name and the extension of the image: ";
                cin.ignore();
                getline(cin, file_name);
                //Handling invalid input
                while (cin.fail() || !isValidExtension(file_name)) {
                    cout << "\nInvalid Input\n";
                    cout << "Enter the name and the extension of the image: ";
                    cin.ignore();
                    getline(cin, file_name);
                }
                //Saving the image with the new name
                image.saveImage(file_name);
                cout << "Saved Successfully\n";
                isSaved = true;
            }
        } else if (choice == 23) {              //Autosave
            int auto_save_int;
            if (autosave_flag) {
                cout << "Autosave is enabled\n";
                cout << "Do you want to disable autosave?\n1) Yes\n2) No\nAnswer: ";
                cin >> auto_save_int;
                while (cin.fail() || !(1 <= auto_save_int && auto_save_int <=2)) {
                    cout << "\nInvalid Input\n";
                    cout << "Do you want to disable autosave?\n1) Yes\n2) No\nAnswer: ";
                    cin >> auto_save_int;
                }
                (auto_save_int == 1) ? autosave_flag = false : autosave_flag = true;
                cout << "Autosave disabled\n";
            } else {
                cout << "Autosave is disabled\n";
                cout << "Do you want to enable autosave?\n1) Yes\n2) No\nAnswer: ";
                cin >> auto_save_int;
                while (cin.fail() || !(1 <= auto_save_int && auto_save_int <=2)) {
                    cout << "\nInvalid Input\n";
                    cout << "Do you want to enable autosave?\n1) Yes\n2) No\nAnswer: ";
                    cin >> auto_save_int;
                }
                (auto_save_int == 1) ? autosave_flag = true : autosave_flag = false;
                cout << "Autosave enabled\n";
            }
        } else if (choice == 24) {           //Exit
            if (isSaved || autosave_flag) {
                cout << "\nExiting...\n" << "Thank you for using our program\n";
                break;
            }
            //Printing the exit message
            cout << "Do you want to save?\n1) Yes\n2) No\nAnswer: ";
            cin >> s;
            //Handling invalid input
            while (cin.fail() || !(1 <= s && s <= 2)) {
                cout << "\nInvalid Input\n";
                cout << "Do you want to save?\n1) Yes\n2) No\nAnswer: ";
                cin.ignore();
                cin >> s;
            }
            if (s == 1) {
                //Getting how to save the image
                cout << "\nSelect how to save the image\n";
                cout << "1) Replace the old image\n2) Save as a new image\n";
                cout << "Type: ";
                cin >> save_type;
                //Handling invalid input
                while (cin.fail() || !(1 <= save_type && save_type <= 2)) {
                    cout << "\nInvalid Input\n";
                    cout << "\nSelect how to save the image\n";
                    cout << "1) Replace the old image\n2) Save as a new image\n";
                    cout << "Type: ";
                    cin >> save_type;
                }
                if (save_type == 1) {           //Replace old image
                    //Saving the image
                    image.saveImage(file_name);
                    cout << "Saved Successfully\n\n";
                    cout << "Exiting...\n" << "Thank you for using our program\n";
                    break;
                } else if (save_type == 2) {    //Save as a new image
                    //Getting the name of the new image
                    cout << "Enter the name and the extension of the image: ";
                    cin.ignore();
                    getline(cin, file_name);
                    //Handling invalid input
                    while (cin.fail() || !isValidExtension(file_name)) {
                        cout << "\nInvalid Input\n";
                        cout << "Enter the name and the extension of the image: ";
                        cin.ignore();
                        getline(cin, file_name);
                    }
                    //Saving the image with the new name
                    image.saveImage(file_name);
                    cout << "Saved Successfully\n\n";
                    cout << "\nExiting...\n" << "Thank you for using our program\n";
                    break;
                }
            } else if (s == 2) {
                cout << "\nExiting...\n" << "Thank you for using our program\n";
                break;
            }
        }
        //Autosaving if enabled
        if (autosave_flag) {
            autosave(image);
            isSaved = true;
        }
    }
    return 0;
}


bool isValidExtension(string& file_name) {
    if (!(file_name.find(".png") == string::npos || file_name.find(".jpg") == string::npos || file_name.find(".jpeg") == string::npos || file_name.find(".bmp") == string::npos || file_name.find(".tga") == string::npos)) {
        return false;
    } else {
        return true;
    }
}

bool isValidFile(string& file_name) {
    if (!isValidExtension(file_name)) {
        return false;
    } else {
        try {
            Image image(file_name);
            return true;
        } catch (exception &e) {
            return false;
        }
    }
}

void invert_image(Image& image) {
    int w = image.width, h = image.height;
    //Looping over each pixel
    for (int i = 0; i < w; ++i) {           //Width
        for (int j = 0; j < h; ++j) {       //Height
            for (int k = 0; k < 3; ++k) {   //Channels
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
}

void black_white(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0; // Initialize average value
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }
            avg /= 3; // Calculate average

            unsigned int new_pixel;
            if (avg > (255/2)){
                new_pixel = 255;
            }
            else {
                new_pixel = 0;
            }
            image(i, j, 0) = new_pixel;
            image(i, j, 1) = new_pixel;
            image(i, j, 2) = new_pixel;
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
}

void flip_vertically(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height / 2; ++j) { //divide height by two
            // Swap pixels between top and bottom rows
            for (int k = 0; k < 3; ++k) {
                unsigned int pxl = image(i, j, k);
                image(i, j, k) = image(i, image.height - 1 - j, k);
                image(i, image.height - 1 - j, k) = pxl;
            }
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
}

void flip_horizontally(Image& image) {
    for (int i = 0; i < image.width / 2; ++i) { //divide width by two
        for (int j = 0; j < image.height; ++j) {
            // Swap pixels between left and right columns
            for (int k = 0; k < 3; ++k) {
                unsigned int pxl = image(i, j, k);
                image(i, j, k) = image(image.width - 1 - i, j, k);
                image(image.width - 1 - i, j, k) = pxl;
            }
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
}

void GrayScaling (Image& image){
    for (int i = 0 ; i < image.width ; ++i){
        for (int j = 0 ; j < image.height ; ++j){

            unsigned int avg = 0;  // Initializing average value.
            for (int k = 0 ; k < image.channels ; ++k){
                avg +=image (i,j,k);
            }
            avg /= 3;  // Calculating the average.

            for (int k = 0 ; k < image.channels ; ++k){
                image (i,j,k) = avg ;  // setting the three intensities (RGB channels) to average value.
            }
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
}

void Lighten(Image& image){
    int LightedPixel;
    for (int i = 0 ; i < image.width ; ++i){
        for (int j = 0 ; j < image.height ; ++j){
            for (int k = 0 ; k < image.channels ; ++k){

                unsigned char PixelValue;  //ensuring that range of pixel value from 0 to 255.
                PixelValue = image.getPixel(i , j , k);  //looping over each pixel in the image.
                LightedPixel = PixelValue * 1.5;  //calculating lighted pixel.
                if (LightedPixel < 0){
                    LightedPixel = 0;
                }
                else if (LightedPixel > 255){
                    LightedPixel = 255;
                }
                image.setPixel(i , j , k , LightedPixel);  //replace native pixels with lighted one.
            }
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
}

void Darken(Image& image){
    int DarkenedPixel;
    for (int i = 0 ; i < image.width ; ++i){
        for (int j = 0 ; j < image.height ; ++j ){
            for (int k = 0 ; k < 3 ; ++k){

                unsigned char PixelValue;   //ensuring that range of pixel value from 0 to 255.
                PixelValue = image.getPixel (i,j,k);  //looping over each pixel in the image.
                DarkenedPixel = PixelValue * 0.5; //calculating darkened pixel.
                if (DarkenedPixel < 0){
                    DarkenedPixel = 0;
                }
                else if (DarkenedPixel > 255){
                    DarkenedPixel = 255;
                }
                image.setPixel(i,j,k,DarkenedPixel); //replace native pixels with darkened one.
            }
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
}

Image rotate(Image image) {
    int w = image.width;
    int h = image.height;

    Image f_image(h, w);

    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < 3; ++k) {
                f_image(j, w - i - 1, k) = image(i, j, k);
            }
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
    return f_image;
}

void add_frame(Image& image, int R, int G, int B) {
    int w = image.width;
    int h = image.height;
    //Left
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < h; ++j) {
            image(i, j, 0) = R;
            image(i, j, 1) = G;
            image(i, j, 2) = B;
        }
    }
    //Right
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < 10; ++j) {
            image(w - 1 - j, i, 0) = R;
            image(w - 1 - j, i, 1) = G;
            image(w - 1 - j, i, 2) = B;
        }
    }
    //Top
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < 10; ++j) {
            image(i, j, 0) = R;
            image(i, j, 1) = G;
            image(i, j, 2) = B;
        }
    }
    //Bottom
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < 10; ++j) {
            image(i, h - j, 0) = R;
            image(i, h - j, 1) = G;
            image(i, h - j, 2) = B;
        }
    }
    //Left Inner
    for (int i = 19; i < 24; ++i) {
        for (int j = 0; j < h; ++j) {
            image(i, j, 0) = 255;
            image(i, j, 1) = 255;
            image(i, j, 2) = 255;
        }
    }
    //Right Inner
    for (int i = w-22; i < w-17; ++i) {
        for (int j = 0; j < h; ++j) {
            image(i, j, 0) = 255;
            image(i, j, 1) = 255;
            image(i, j, 2) = 255;
        }
    }
    //Top Inner
    for (int i = 0; i < w; ++i) {
        for (int j = 19; j < 24; ++j) {
            image(i, j, 0) = 255;
            image(i, j, 1) = 255;
            image(i, j, 2) = 255;
        }
    }
    //Bottom Inner
    for (int i = 0; i < w; ++i) {
        for (int j = h-22; j < h-17; ++j) {
            image(i, j, 0) = 255;
            image(i, j, 1) = 255;
            image(i, j, 2) = 255;
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
}

vector<vector<vector<ll>>> prefix_sum(Image image) {
    vector<vector<vector<ll>>> prefix(image.width, vector<vector<ll>>(image.height, vector<ll>(3)));
    for (ll i = 1; i < image.width; ++i) {
        prefix[i][0][0] = image(i, 0, 0) + prefix[i-1][0][0];
        prefix[i][0][1] = image(i, 0, 1) + prefix[i-1][0][1];
        prefix[i][0][2] = image(i, 0, 2) + prefix[i-1][0][2];
    }
    for (ll j = 1; j < image.height; ++j) {
        prefix[0][j][0] = image(0, j, 0) + prefix[0][j-1][0];
        prefix[0][j][1] = image(0, j, 1) + prefix[0][j-1][1];
        prefix[0][j][2] = image(0, j, 2) + prefix[0][j-1][2];
    }
    for (ll i = 1; i < image.width; ++i) {
        for (ll j = 1; j < image.height; ++j) {
            prefix[i][j][0] = image(i, j, 0) + prefix[i-1][j][0] + prefix[i][j-1][0] - prefix[i-1][j-1][0];
            prefix[i][j][1] = image(i, j, 1) + prefix[i-1][j][1] + prefix[i][j-1][1] - prefix[i-1][j-1][1];
            prefix[i][j][2] = image(i, j, 2) + prefix[i-1][j][2] + prefix[i][j-1][2] - prefix[i-1][j-1][2];
        }
    }
    return prefix;
}

void blur(Image& image) {
    int w = image.width;
    int h = image.height;
    int r = 100;
    int kernel = 2 * r + 1;
    int area = kernel * kernel;
    ll sum;
    int right, left, up, down;
    vector<vector<vector<ll>>> prefix = prefix_sum(image);
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < 3; ++k) {
                right = i+r;
                left = i-r-1;
                up = j-r-1;
                down = j+r;
                if (right >= w-1) {
                    right = w-1;
                }
                if (left <= 0) {
                    left = 0;
                }
                if (up <= 0) {
                    up = 0;
                }
                if (down >= h-1) {
                    down = h-1;
                }
                sum = 0;
                sum = prefix[right][down][k] - prefix[left][down][k] - prefix[right][up][k] + prefix[left][up][k];
                image(i, j, k) = sum / area;
            }
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
}

void cropImage(Image& image, int firstCorner, int secondCorner, int cropWidth, int cropHeight) {
    // Create a new image for the cropped region
    Image croppedImage(cropWidth, cropHeight);

    // Copy pixels from the original image to the cropped image
    for (int i = firstCorner; i < firstCorner + cropWidth; ++i) {
        for (int j = secondCorner; j < secondCorner + cropHeight; ++j) {
            for (int k = 0; k < 3; ++k) {
                croppedImage(i - firstCorner, j - secondCorner, k) = image(i, j, k);
            }
        }
    }
    image = croppedImage;
    //Success message
    cout << "Filter Applied Successfully\n";
}

void resizeImage(Image& image) {
    double newWidth,newHeight;
    cout << "Enter the new width: ";
    cin >> newWidth;
    while (cin.fail() || newWidth <= 0) {
        cout << "\nInvalid Dimensions\n";
        cout << "Enter the new width: ";
        cin >> newWidth;
    }
    cout << "Enter the new height: ";
    cin >> newHeight;
    while (cin.fail() || newHeight <= 0) {
        cout << "\nInvalid Dimensions\n";
        cout << "Enter the new height: ";
        cin >> newHeight;
    }
    Image resizedImage (newWidth, newHeight);
    double x,y;
    // Calculate scaling factors
    x = image.width / newWidth;
    y = image.height / newHeight;

    for (int i = 0; i < newWidth; ++i) {
        for (int j = 0; j < newHeight; ++j) {
            for (int k = 0; k < 3; ++k) {
                resizedImage(i, j, k) = round(image(x * i, y * j, k));
            }
        }
    }
    image = resizedImage;
    //Success message
    cout << "Filter Applied Successfully\n";
}

void dark_red(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Get the red channel value and set green and blue channels to zero
            unsigned int redValue = image(i, j, 0); // Red channel
            image(i, j, 1) = 0; // Green channel (set to zero)
            image(i, j, 2) = 0; // Blue channel (set to zero)

            // Set all channels to the red channel value
            image(i, j, 0) = redValue;
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
}

void infrared(Image& image) {

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Extract RGB components
            unsigned int red = image(i, j, 0); // Red channel
            unsigned int green = image(i, j, 1); // Green channel
            unsigned int blue = image(i, j, 2); // Blue channel

            // Calculate brightness (average of RGB values)
            unsigned int avg = (red + green + blue) / 3;

            // Calculate the proportion of red based on brightness
            unsigned int redProportion = 255 - avg;

            // Set pixel values based on brightness
            image(i, j, 0) = 200; // Red channel
            image(i, j, 1) =redProportion ; // Green channel
            image(i, j, 2) = redProportion; // Blue channel
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
}

void purple (Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int red = image(i, j, 0); // Red channel
            unsigned int green = image(i, j, 1); // Green channel
            unsigned int blue = image(i, j, 2); // Blue channel
            image(i, j, 0) = red*0.6;  // red channel
            image(i, j, 1) = green*0.5; // Green channel
            image(i, j, 2) = blue*0.8;// blue channel
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
}

void sunlight (Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int red = image(i, j, 0); // Red channel
            unsigned int green = image(i, j, 1); // Green channel
            unsigned int blue = image(i, j, 2); // Blue channel
            image(i, j, 0) = red*0.9;  // red channel
            image(i, j, 1) = green*0.9; // Green channel
            image(i, j, 2) = blue*0.7;// blue channel
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
}

void tv (Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if(j%2 == 0) {
                image(i, j, 0) = 0;  // red channel
                image(i, j, 1) = 0; // Green channel
                image(i, j, 2) = 0;// blue channel
            }
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
}

void slytherin(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int red = image(i, j, 0); // Red channel
            unsigned int green = image(i, j, 1); // Green channel
            unsigned int blue = image(i, j, 2); // Blue channel
            image(i, j, 0) = red *0.6;  // red channel
            image(i, j, 1) = green *0.5; // Green channel
            image(i, j, 2) = blue *0.8;// blue channel
        }
    }

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int red = image(i, j, 0); // Red channel
            unsigned int green = image(i, j, 1); // Green channel
            unsigned int blue = image(i, j, 2); // Blue channel
            image(i, j, 0) = red * 0.9;  // red channel
            image(i, j, 1) = green * 0.9; // Green channel
            image(i, j, 2) = blue * 0.7;// blue channel
        }
    }

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Extract RGB components
            unsigned int red = image(i, j, 0); // Red channel
            unsigned int green = image(i, j, 1); // Green channel
            unsigned int blue = image(i, j, 2); // Blue channel

            // Calculate brightness (average of RGB values)
            unsigned int avg = (red + green + blue) / 3;

            // Calculate the proportion of red based on brightness
            unsigned int redProportion = 255 - avg;

            // Set pixel values based on brightness
            image(i, j, 0) = 200; // Red channel
            image(i, j, 1) = redProportion ; // Green channel
            image(i, j, 2) = redProportion; // Blue channel
        }
    }

    for (int i = 0; i < image.width; ++i) {           //Width
        for (int j = 0; j < image.height; ++j) {       //Height
            for (int k = 0; k < 3; ++k) {   //Channels
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
}

void oil(Image& image) {
    int radius = 2;
    int intensity = 3;
    int w = image.width;
    int h = image.height;

    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            vector<int> intensity_count(256, 0);
            vector<int> avg_red(256, 0);
            vector<int> avg_green(256, 0);
            vector<int> avg_blue(256, 0);
            // Looping over neighboring pixels
            for (int x = i - radius; x < i + radius + 1; ++x) {
                for (int y = j - radius; y < j + radius + 1; ++y) {
                    if (x >= 0 && x < w) {
                        if (y >= 0 && y < h) {
                            int Red = image(x, y, 0);
                            int Green = image(x, y, 1);
                            int Blue = image(x, y, 2);

                            int intensitylevel = ((Red + Green + Blue) / 3 * intensity) / 255;

                            intensity_count[intensitylevel]++;
                            avg_red[intensitylevel] += Red;
                            avg_green[intensitylevel] += Green;
                            avg_blue[intensitylevel] += Blue;
                        }
                    }
                }
            }

            int _max = 0;
            for (int c = 1; c < 256; ++c) {
                if (intensity_count[c] > intensity_count[_max]) {
                    _max = c;
                }
            }

            if (intensity_count[_max] != 0) {
                image(i, j, 0) = avg_red[_max] / intensity_count[_max];
                image(i, j, 1) = avg_green[_max] / intensity_count[_max];
                image(i, j, 2) = avg_blue[_max] / intensity_count[_max];
            }
        }
    }
    //Success message
    cout << "Filter Applied Successfully\n";
}

void skew(Image& image) {
    double angle;
    cout << "Enter the angle: ";
    cin >> angle;
    //Handling invalid input
    while (cin.fail() || !(0 < angle && angle < 180) || angle == 90) {
        cout << "\nInvalid Input\n";
        cout << "Enter the angle: ";
        cin >> angle;
    }
    double shift = image.height * ( 1.0 / tan(M_PI * angle / 180) );
    Image skewedImage(image.width + shift, image.height);
    // Loop through each pixel in the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Copy pixel value from original image to filtered image
            skewedImage( i - j * ( 1.0 / tan(M_PI * angle / 180) ) + shift, j , 0) = image(i, j, 0);
            skewedImage(i - j * ( 1.0 / tan(M_PI * angle / 180) )  + shift, j , 1) = image(i, j, 1);
            skewedImage(i - j * ( 1.0 / tan(M_PI * angle / 180) )  + shift, j , 2) = image(i, j, 2);
        }
    }
    // Update the original image with the filtered image
    image = skewedImage;
}

void edge_detection(Image& image) {
    GrayScaling(image);
    Image edge(image.width, image.height);
    for (int i = 1; i < image.width - 1; ++i) {
        for (int j = 1; j < image.height - 1; ++j) {
            double hor_gradient;
            double ver_gradient;
            for(int k = 0; k < 3; ++k) {
                int topleft = image(i - 1, j - 1, k);
                int left = image(i - 1, j, k);
                int bottomleft = image(i - 1, j + 1, k);

                int above = image(i, j - 1, k);
                int below = image(i, j + 1, k);

                int topright = image(i + 1, j - 1, k);
                int right = image(i + 1, j, k);
                int bottomright = image(i + 1, j + 1, k);

                hor_gradient = -topleft + topright - (2 * left) + (2 * right) - bottomleft + bottomright;
                ver_gradient = topleft + (2 * above) + topright - bottomleft - (2 * below) - bottomright;

                double gradient_magnitude = sqrt(pow(hor_gradient, 2) + pow(ver_gradient, 2));

                int threshold = 100; // Adjust this threshold as needed
                if (gradient_magnitude > threshold) {
                    // Set the pixel to black
                    edge(i, j, k) = 0;
                } else {
                    // Set the pixel to white
                    edge(i, j, k) = 255;
                }
            }
        }
    }
    image = edge;
    //Success message
    cout << "Filter Applied Successfully\n";
}

void merge(Image& image, Image img2) {
    int w = image.width;
    int h = image.height;
    Image resizedImage (w, h);
    double x,y;
    // Calculate scaling factors
    x = img2.width / w;
    y = img2.height / h;
    //Resizing
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < 3; ++k) {
                resizedImage(i, j, k) = round(img2(x * i, y * j, k));
            }
        }
    }
    img2 = resizedImage;
    Image merged(w, h);
    //Merging
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            int R, G, B;
            R = (image(i, j, 0) + img2(i, j, 0)) / 2;
            G = (image(i, j, 1) + img2(i, j, 1)) / 2;
            B = (image(i, j, 2) + img2(i, j, 2)) / 2;
            merged(i, j, 0) = R;
            merged(i, j, 1) = G;
            merged(i, j, 2) = B;
        }
    }
    image = merged;
    //Success message
    cout << "Filter Applied Successfully\n";
}

void autosave(Image image) {
    image.saveImage("autosave.jpg");
}