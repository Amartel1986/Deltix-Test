#pragma once

#include "Processor.h"

#include <cassert>

namespace DiffProcessor
{
    Processor::Processor(long limit) :
        mLimit(limit)
    {
        // TODO: initialization.
    }
    Processor::~Processor()
    {
        // TODO: Free resources.
    }

    void Processor::do_process(SortedLimitedList<double> &must_be_equal_to, const SortedLimitedList<double> &expected_output)
    {
        // TODO: make "must_be_equal_to" list equal to "expected_output".
        // 0. Processor will be created once and then will be used billion times.
        // 1. Use methods: AddFirst, AddLast, AddBefore, AddAfter, Remove to modify list.
        // 2. Do not change expected_output list.
        // 3. At any time number of elements in list could not exceed the "Limit".
        // 4. "Limit" will be passed into Processor's constructor. All "must_be_equal_to" and "expected_output" lists will have the same "Limit" value.
        // 5. At any time list elements must be in non-descending order.
        // 6. Implementation must perform minimal possible number of actions (AddFirst, AddLast, AddBefore, AddAfter, Remove).
        // 7. Implementation must be fast and do not allocate excess memory.

        assert(expected_output.count() <= mLimit);

        bool need_iterate = true;
        while (need_iterate) {
            need_iterate = false;
            SortedLimitedList<double>::iterator lhs = must_be_equal_to.first();
            SortedLimitedList<double>::const_iterator rhs = expected_output.first();

            while (lhs != must_be_equal_to.end() || rhs != expected_output.end()) {
                if (lhs == must_be_equal_to.end()) {
                    must_be_equal_to.add_last(*rhs);
                    ++rhs;
                } else if (rhs == expected_output.end()) {
                    SortedLimitedList<double>::iterator tmp = lhs;
                    ++tmp;
                    must_be_equal_to.remove(lhs);
                    lhs = tmp;
                } else if (*lhs < *rhs) {
                    SortedLimitedList<double>::iterator tmp = lhs;
                    ++tmp;
                    must_be_equal_to.remove(lhs);
                    lhs = tmp;
                } else if (*lhs > *rhs) {
                    if (must_be_equal_to.count() < mLimit) {
                        must_be_equal_to.add_before(lhs, *rhs);
                    } else {
                        need_iterate = true;
                    }
                    ++rhs;
                } else {
                    ++lhs;
                    ++rhs;
                }
            }
        }
    }
}
