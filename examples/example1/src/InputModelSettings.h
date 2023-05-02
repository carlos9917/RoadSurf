#pragma once
#include "Constants.h"
#include "Options.h"
#include <json/json.h>
#include <time.h>

//!> model settings given as input by modelRunner.cpp
struct InputModelSettings
{
  InputModelSettings() = default;
  explicit InputModelSettings(const Json::Value& pJson, const Options& pOptions);

  int SimLen = 0;          //!< Lenght of simulation
  int use_coupling = 0;    //!< 1 if coupling is used
  int use_relaxation = 0;  //!< 1 if relaxation is used

  double DTSecs = 30.0;                    //!< time step in seconds
  double tsurfOutputDepth = -9999.9;       //!< Depth to interpolate output surface temperature
  int thread = 0;                          //!< ID of thread doing the calcuations
  int statID = 0;                          //!< ID of point where the model is runned
  int simID = 0;                           //!< ID of simulation
  int use_iterative_heat_balance = 0;      //!< 1 if Crank–Nicholson sheme is used
  int coupling_minutes = 180;              //!< Coupling lenght in minutes
  double couplingEffectReduction=4.0*3600; //!< Parameter used to calculate radiation
                                           //!< coefficient after coupling
  int outputStep = 60;                     //!< frequency of output in minutes
  time_t forecast_time;  //!< Wall clock time, possibly simulated one
  time_t start_time;     //!< Model simulation start time
  time_t end_time;       //!< Model simulation end time
};
