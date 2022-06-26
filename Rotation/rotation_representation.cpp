//  Rotation can be represented in 4 types : Rotation, AngleAxis, EulerAngle, Quaternion 
//  This code demonstrate how to represent rotation in various ways and how to convert expressions among themselves

#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;

int main(int argc, char ** argv)
{
    //  Rotation Matrix
    Eigen::Matrix3d rotation_mat = Eigen::Matrix3d::Identity();

    //  Angle-Axis rotation vector
    //  Rotate 45 degreees along Y axis
    Eigen::AngleAxisd rotation_vect(M_PI / 4, Eigen::Vector3d(0,1,0));

    //  Convert AngleAxis form to Rotation Matrix form
    rotation_mat = rotation_vect.toRotationMatrix();

    //  Rotate a vector with a Angel-axis
    //  you can get results in 2 ways

    Eigen::Vector3d basic_vect(1,0,0);
    Eigen::Vector3d rotated_vect1 = rotation_vect * basic_vect;
    Eigen::Vector3d rotated_vect2 = rotation_mat * basic_vect;

    cout << rotated_vect1 << endl;
    cout << endl;
    cout << rotated_vect2 << endl;
    cout << endl;


    //  Convert Rotation Matrix into Euler Angle
    //  ZYX order, roll-pitch-yaw(2,1,0) 
    Eigen::Vector3d euler_angle = rotation_mat.eulerAngles(2,1,0); 
    
    cout << euler_angle << endl;
    cout << endl;

    //  Convert AngleAxis, Rotation Matrix form to Quaternion form
    //  order of coeffs is (x,y,z,w)
    //  (x,y,z) is imaginary part, w is real part
    Eigen::Quaterniond quat1 = Eigen::Quaterniond(rotation_vect);
    Eigen::Quaterniond quat2 = Eigen::Quaterniond(rotation_mat);
    
    cout << quat1.coeffs() << endl;  
    cout << endl;
    cout << quat2.coeffs() << endl;  
    cout << endl;

    //  Rotate a vector with a quaternion
    //  quaternion multiplication is a "overloaded" operation! Don't be Confused!
    //  q * v is equal to qvq^{-1}

    Eigen::Vector3d rotated_vect3 = quat1 * basic_vect;
    cout << rotated_vect3 << endl;
    cout << endl;


    //  Euclidean Transformation Matrix
    //  it is a 4 by 4 matrix
    Eigen::Isometry3d Transform = Eigen::Isometry3d::Identity();

    //  How much do wo rotate and translate?
    //  it is the procedure of making Transformation matrix 
    //  rotate 45 degrees, translate (2,2,2)
    Transform.rotate(rotation_vect);
    Transform.pretranslate(Eigen::Vector3d(2,2,2));

    Eigen::Vector3d tranformed_vect = Transform * basic_vect;  //   (R*v + t) == (Tv)
    cout << tranformed_vect << endl;
    cout << endl;

    return 0;
}