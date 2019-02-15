#include "VectorTests.h"

TEST_F(VectorTest, IsEmpty) { 

    ASSERT_TRUE(m_v0->Empty());
    ASSERT_TRUE(m_v0_copy->Empty());
    ASSERT_TRUE(m_v1->Empty());
    ASSERT_TRUE(m_v1_copy.Empty());

    m_v0->PushBack(1);
    ASSERT_EQ(m_v0->Front(), m_v0->Back());
    ASSERT_EQ( 1, m_v0->Access(0));
    ASSERT_EQ(-1, m_v0->Access(2));
    m_v0->PushBack(2);
    m_v0->PushBack(3);
    ASSERT_EQ(3, m_v0->Access(2));
    m_v0->PushBack(4);
    m_v0->PushBack(5);
    ASSERT_EQ(4, m_v0->Search(5));
    ASSERT_EQ(-1, m_v0->Search(44));

    m_v0->PopBack();
    m_v0->PopBack();
    m_v0->PopBack();
    m_v0->PushBack(3);
    m_v0->PushBack(4);
    m_v0->PushBack(5);
    //m_v0->Traverse();
    ASSERT_FALSE(m_v0->Empty());

    m_v0->Insert(577,44);
    //m_v0->Traverse();

    m_v0->PopBack();
    m_v0->PopBack();
    m_v0->PopBack();
    m_v0->PopBack();
    m_v0->PopBack();
    m_v0->PopBack();
    m_v0->PopBack();
    // m_v1->Insert(5,0);
    // m_v1->Insert(4,0);
    // m_v1->Insert(3,0);
    // m_v1->Insert(2,0);
    // m_v1->Insert(1,0);
    // m_v1->Delete(3);
    
    m_v1->PushBack(9);
    m_v1->PushBack(8);
    m_v1->PushBack(7);
    m_v1->PushBack(6);

    m_v1_copy.PushBack(1);
    m_v1_copy.PushBack(2);
    m_v1_copy.PushBack(3);
    m_v1_copy.PushBack(4);

    m_v1_copy.Traverse();
    m_v1->Traverse();
    
    m_v1->Swap(m_v1_copy);
    m_v1_copy.Traverse();
    m_v1->Traverse();
    m_v1->Clear();
    m_v1->Traverse();
}

int main (int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}