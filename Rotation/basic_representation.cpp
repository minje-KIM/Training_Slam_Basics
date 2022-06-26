#include <iostream>
#include <ctime>

//  Eigen library 
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace std;


int main(int argc, char **argv)
{
    //  Matrix Representation in Eigen
    //  Matrix< <Data type> <row> <column> >
    //  there are 2 types of representation of Matrix
    Eigen::Matrix3d mat_3d;  //3 by 3 matrix
    Eigen::Matrix<float,2,3> mat_23;   //2 by 3 matrix
    

    //  Vector Representation in Eigen
    //  there are 2 types of representation of 3-dimensional Vector
    Eigen::Vector3d vec_3d(0,0,0);
    Eigen::Matrix<float,3,1> vec_31;


    //  How to initialized these vectors and Matricies?
    mat_3d << 1,2,3,4,5,6,7,8,9;
    mat_23 << 4,2,7,9,3,0;
    vec_3d << 1,2,3;
    vec_31 << 4,5,6;

    //  showing matrices and vectors in terminal
    cout << mat_3d<< endl;
    cout << endl;
    cout << mat_23<< endl;
    cout << endl;

    cout << vec_3d<< endl;
    cout << endl;
    cout << vec_31<< endl;
    cout << endl;

    //  Multiplying a Matrix with a vector
    //  cannot multiply 2 diffrent types of mat,vec. 
    //Eigen::Matrix<float,2,1> mat_21 = mat_23 * vec_3d;
    Eigen::Matrix<float,2,1> multiplied_21 = mat_23 * vec_31;
    Eigen::Vector3d multiplied_31 = mat_3d * vec_3d;
    
    cout << multiplied_21<< endl;
    cout << endl;
    cout << multiplied_31<< endl;
    cout << endl;

    return 0;
}