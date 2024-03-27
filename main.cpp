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

int main() {
    //Initializing variables
    string file_name;
    int choice, save_type;
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
        cout << "1) Load Another Image\n2) Grayscale Conversion\n3) Black and White\n4) Invert Image\n5) Flip Vertically\n6) Flip Horizontally\n7) Save Image\n8) Exit\n";
        cout << "Choice: ";
        cin >> choice;
        //Handling invalid input
        while (cin.fail() || !(1 <= choice && choice <= 8)) {
            cout << "\nInvalid Input\n";
            cout << "\nMain menu\n";
            cout << "1) Load Another Image\n2) Grayscale Conversion\n3) Black and White\n4) Invert Image\n5) Flip Vertically\n6) Flip Horizontally\n7) Save Image\n8) Exit\n";
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
            Image image(file_name);
        } else if (choice == 2) {           //Grayscale Conversion
            cout << "Under Development\n";
        } else if (choice == 3) {           //Black and White
            black_white(image);
        } else if (choice == 4) {           //Invert Image
            invert_image(image);
        } else if (choice == 5) {           //Flip Vertically
            flip_vertically(image);
        } else if (choice == 6) {           //Flip Horizontally
            flip_horizontally(image);
        } else if (choice == 7) {           //Save
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
        } else if (choice == 8) {           //Exit
            //Printing the exit message
            cout << "Exiting...\n" << "Thank you for using our program\n";
            break;
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
