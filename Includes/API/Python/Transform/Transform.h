/*************************************************************************
> File Name: Transform.h
> Project Name: CubbyFlow
> This code is based on Jet Framework that was created by Doyub Kim.
> References: https://github.com/doyubkim/fluid-engine-dev
> Purpose: Transform functions for CubbyFlow Python API.
> Created Time: 2018/01/29
> Copyright (c) 2018, Chan-Ho Chris Ohk
*************************************************************************/
#ifndef CUBBYFLOW_PYTHON_TRANSFORM_H
#define CUBBYFLOW_PYTHON_TRANSFORM_H

#include <pybind11/pybind11.h>

void AddTransform2(pybind11::module& m);
void AddTransform3(pybind11::module& m);

#endif