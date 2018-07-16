/*
* Copyright 2010-2018 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <intrin.h>

int aws_atomic_cas(int *dst, int compare, int value) {
    return InterlockedCompareExchange((unsigned*)dst, (unsigned)value, (unsigned)compare) == (unsigned)compare;
}

int aws_atomic_cas_ptr(void **dst, void *compare, void *value) {
    return InterlockedCompareExchangePointer(dst, value, compare) == compare;
}
