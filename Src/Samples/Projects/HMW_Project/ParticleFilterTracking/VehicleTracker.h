#ifndef VEHICLETRACKER
#define VEHICLETRACKER

//=================================================
//Please add headers here:
#include<VehicleDetector.h>
#include<VirtualScanGlobalizer.h>
#include<VehicleParticleFilter.h>
#include<sync.h>
#include<fastconvexfitting.h>

//=================================================
#include<RobotSDK.h>
namespace RobotSDK_Module
{

//=================================================
//Node configuration

#undef NODE_CLASS
#define NODE_CLASS VehicleTracker

#undef INPUT_PORT_NUM
#define INPUT_PORT_NUM 2

#undef OUTPUT_PORT_NUM
#define OUTPUT_PORT_NUM 1

//=================================================
//Params types configuration

//If you need to refer params type of other node class, please uncomment below and comment its own params type.
//NODE_PARAMS_TYPE_REF(RefNodeClassName)
class NODE_PARAMS_TYPE : public NODE_PARAMS_BASE_TYPE
{

};

//=================================================
//Vars types configuration

//If you need to refer vars type of other node class, please uncomment below and comment its own vars type.
//NODE_VARS_TYPE_REF(RefNodeClassName)
class NODE_VARS_TYPE : public NODE_VARS_BASE_TYPE
{
public:
    ADD_VAR(int, particlenum, 5000)
    ADD_VAR(float, state_x_min, -2)
    ADD_VAR(float, state_x_max, 2)
    ADD_VAR(float, state_y_min, -2)
    ADD_VAR(float, state_y_max, 2)
    ADD_VAR(float, state_theta_min,-0.2)
    ADD_VAR(float, state_theta_max,0.2)
    ADD_VAR(float, state_theta_sigma,0.2)
    ADD_VAR(float, state_v_min, -10)
    ADD_VAR(float, state_v_max, 10)
    ADD_VAR(float, state_v_sigma, 5)
    ADD_VAR(float, state_width_min, -2)
    ADD_VAR(float, state_width_max, 2)
    ADD_VAR(float, state_length_min, -2)
    ADD_VAR(float, state_length_max, 2)
    ADD_VAR(float, threshold, 0.1)
public:
    MEASUREDATA_TYPE(Vehicle) measuredata;
public:
    ADD_SYNC(sync,1)
public:
    QTime curtimestamp;
    cv::Mat curtransform;
    float curtheta;
    cv::Mat localheadvec;
    std::vector<int> objectid;
    std::vector<STATE_TYPE(Vehicle)> objectstate;
public:
    FastRectangleFitting * fitter;
};

//=================================================
//Data types configuration

//If you need to refer data type of other node class, please uncomment below and comment its own data type.
//NODE_DATA_TYPE_REF(RefNodeClassName)
class NODE_DATA_TYPE : public NODE_DATA_BASE_TYPE
{
public:
    cv::Mat transform;
    std::vector<int> objectid;
    std::vector<STATE_TYPE(Vehicle)> objectstate;
    std::vector<float> weights;
};

//=================================================
//You can declare functions here


//=================================================
}

#endif
