
#ifndef __VECTORTESTS_H__
#define __VECTORTESTS_H__

#include <gtest/gtest.h>
#include "Vector.h"

class VectorTest : public ::testing::Test {

protected:

    void SetUp() override {
        m_v0        = new Vector<int>();
        m_v0_copy   = new Vector<int>(*m_v0);
        m_v1        = new Vector<float>(10);
        m_v1_copy   = *m_v1;
    }

    void TearDown() override {
        delete m_v0;
        delete m_v0_copy;
        delete m_v1;
    }

    Vector<int>     *m_v0;
    Vector<int>     *m_v0_copy;
    Vector<float>   *m_v1;
    Vector<float>    m_v1_copy;
};

#endif
