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

int main() {
    //Initializing the variables
    string file_name;
    int choice, save_type, s, f;
    //Welcome menu
    cout << "Welcome to the BabyPhotoShop program\n" << "This program allows you to apply filters to images\n\n";
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
        cout << "\nMain menu\n";
        cout << "1) Load Another Image\n2) Grayscale Conversion\n3) Black and White\n4) Invert Image\n5) Flip\n6) Lighten\n7) Darken\n8) Save Image\n9) Exit\n";
        cout << "Choice: ";
        cin >> choice;
        //Handling invalid input
        while (cin.fail() || !(1 <= choice && choice <= 9)) {
            cout << "\nInvalid Input\n";
            cout << "\nMain menu\n";
            cout << "1) Load Another Image\n2) Grayscale Conversion\n3) Black and White\n4) Invert Image\n5) Flip\n6) Lighten\n7) Darken\n8) Save Image\n9) Exit\n";
            cout << "Choice: ";
            cin >> choice;
        }
        //Applying the filters as entered
        if (choice == 1) {                  //Load Another Image
            //Getting the file name
            cout << "Enter the file name and its extension (PNG/JPG/BMP/TGA): ";
            cin.ignore();
            getline(cin, file_name);
            //Handling invalid filenames
            while (!isValidFile(file_name)) {
                cout << "Enter the file name and its extension (PNG/JPG/BMP/TGA): ";
                cin.ignore();
                getline(cin, file_name);
            }
            //Loading the other image
            image.loadNewImage(file_name);
        } else if (choice == 2) {           //Grayscale Conversion
            GrayScaling(image);
        } else if (choice == 3) {           //Black and White
            black_white(image);
        } else if (choice == 4) {           //Invert Image
            invert_image(image);
        } else if (choice == 5) {           //Flip
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
        } else if (choice == 6) {           //Lighten
            Lighten(image);
        } else if (choice == 7) {           //Darken
            Darken(image);
        } else if (choice == 8) {           //Save
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
            }
        } else if (choice == 9) {           //Exit
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
                    cout << "Exiting...\n" << "Thank you for using our program\n";
                    break;
                }
            } else if (s == 2) {
                cout << "Exiting...\n" << "Thank you for using our program\n";
                break;
            }
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