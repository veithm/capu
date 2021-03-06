/*
 * Copyright (C) 2013 BMW Car IT GmbH
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <container/VectorTest.h>
#include "capu/container/String.h"

namespace capu
{
    VectorTest::VectorTest()
    {

    }

    VectorTest::~VectorTest()
    {

    }

    void VectorTest::SetUp()
    {

    }

    void VectorTest::TearDown()
    {

    }

    TEST_F(VectorTest, Constructor)
    {
        Vector<uint32_t> vector;
        EXPECT_EQ(0U, vector.size());
    }

    TEST_F(VectorTest, ConstructorWithCapacity)
    {
        Vector<uint32_t> vector(3);
        EXPECT_EQ(0u, vector.size());
    }

    TEST_F(VectorTest, ConstructorWithCapacityAndValue)
    {
        Vector<uint32_t> vector(3, 5);

        EXPECT_EQ(5u, vector[0]);
        EXPECT_EQ(5u, vector[1]);
        EXPECT_EQ(5u, vector[2]);
    }

    TEST_F(VectorTest, CopyConstructor)
    {
        Vector<uint32_t>* vector = new Vector<uint32_t>(32);

        for(uint32_t i = 0; i < 32; ++i)
        {
            vector->push_back(i);
        }

        const Vector<uint32_t> vectorCopy(*vector);
        delete vector;

        for(uint32_t i = 0; i < 32; ++i)
        {
            EXPECT_EQ(i, vectorCopy[i]);
        }

        EXPECT_EQ(32u, vectorCopy.size());
    }

    TEST_F(VectorTest, PushBack)
    {
        Vector<uint32_t> vector;

        vector.push_back(42u);
        vector.push_back(47u);

        EXPECT_EQ(42u, vector[0]);
        EXPECT_EQ(47u, vector[1]);
    }

    TEST_F(VectorTest, PushBack2)
    {
        Vector<uint32_t> vector(1);

        vector.push_back(42u);
        vector.push_back(47u);

        EXPECT_EQ(42u, vector[0]);
        EXPECT_EQ(47u, vector[1]);
    }

    TEST_F(VectorTest, PushBack3)
    {
        Vector<uint32_t> vector(0);

        vector.push_back(42u);

        EXPECT_EQ(42u, vector[0]);
    }

    TEST_F(VectorTest, IteratorInc)
    {
        Vector<uint32_t> vector;

        vector.push_back(1u);
        vector.push_back(2u);
        vector.push_back(3u);
        vector.push_back(4u);

        Vector<uint32_t>::Iterator current = vector.begin();

        EXPECT_EQ(1u, *current);
        ++current;
        EXPECT_EQ(2u, *current);
        ++current;
        EXPECT_EQ(3u, *current);
        ++current;
        EXPECT_EQ(4u, *current);
    }

    TEST_F(VectorTest, IteratorDec)
    {
        Vector<uint32_t> vector;

        vector.push_back(1u);
        vector.push_back(2u);
        vector.push_back(3u);
        vector.push_back(4u);

        Vector<uint32_t>::Iterator end = vector.end();
        --end;
        EXPECT_EQ(4u, *end);
        --end;
        EXPECT_EQ(3u, *end);
        --end;
        EXPECT_EQ(2u, *end);
        --end;
        EXPECT_EQ(1u, *end);
    }

    TEST_F(VectorTest, IteratorNotEqual)
    {
        Vector<uint32_t> vector;

        vector.push_back(1u);
        vector.push_back(2u);
        vector.push_back(3u);
        vector.push_back(4u);

        Vector<uint32_t>::Iterator start = vector.begin();
        Vector<uint32_t>::Iterator end = vector.end();

        EXPECT_TRUE(start != end);
        end = start;
        EXPECT_FALSE(start != end);

    }

    TEST_F(VectorTest, IteratorSmaller)
    {
        Vector<uint32_t> vector;

        vector.push_back(1u);
        vector.push_back(2u);
        vector.push_back(3u);
        vector.push_back(4u);

        Vector<uint32_t>::Iterator start = vector.begin();
        Vector<uint32_t>::Iterator end = vector.end();

        EXPECT_TRUE(start < end);
        EXPECT_FALSE(end < start);
    }

    TEST_F(VectorTest, IteratorBigger)
    {
        Vector<uint32_t> vector;

        vector.push_back(1u);
        vector.push_back(2u);
        vector.push_back(3u);
        vector.push_back(4u);

        Vector<uint32_t>::Iterator start = vector.begin();
        Vector<uint32_t>::Iterator end = vector.end();

        EXPECT_TRUE(end > start);
        EXPECT_FALSE(start > end);
    }

    TEST_F(VectorTest, IteratorAddValue)
    {
        Vector<uint32_t> vector;

        vector.push_back(1u);
        vector.push_back(2u);
        vector.push_back(3u);
        vector.push_back(4u);

        Vector<uint32_t>::Iterator start = vector.begin();

        EXPECT_EQ(1u, *(start + 0u));
        EXPECT_EQ(2u, *(start + 1u));
        EXPECT_EQ(3u, *(start + 2u));
        EXPECT_EQ(4u, *(start + 3u));
    }

    TEST_F(VectorTest, IteratorSubValue)
    {
         Vector<uint32_t> vector;

        vector.push_back(1u);
        vector.push_back(2u);
        vector.push_back(3u);
        vector.push_back(4u);

        Vector<uint32_t>::Iterator end = vector.end();

        EXPECT_EQ(4u, *(end - 1u));
        EXPECT_EQ(3u, *(end - 2u));
        EXPECT_EQ(2u, *(end - 3u));
        EXPECT_EQ(1u, *(end - 4u));
    }

    TEST_F(VectorTest, Iterator)
    {
        Vector<uint32_t> vector;

        vector.push_back(42u);
        vector.push_back(47u);

        Vector<uint32_t> vector2;

        for (Vector<uint32_t>::Iterator iter = vector.begin(); iter != vector.end(); ++iter)
        {
            vector2.push_back(*iter);
        }

        EXPECT_EQ(42u, vector2[0]);
        EXPECT_EQ(47u, vector2[1]);
    }

    TEST_F(VectorTest, IteratorOnConstVector)
    {
        Vector<uint32_t> vector;

        const Vector<uint32_t>& constVector = vector;

        vector.push_back(42u);
        vector.push_back(47u);

        Vector<uint32_t> vector2;

        for (Vector<uint32_t>::ConstIterator iter = constVector.begin(); iter != constVector.end(); ++iter)
        {
            vector2.push_back(*iter);
        }

        EXPECT_EQ(2u, vector2.size());
        EXPECT_EQ(42u, vector2[0]);
        EXPECT_EQ(47u, vector2[1]);
    }

    TEST_F(VectorTest, IteratorOnConstVectorWithInitialCapacity)
    {
        Vector<uint32_t> vector(32);

        const Vector<uint32_t>& constVector = vector;

        vector.push_back(42u);
        vector.push_back(47u);

        Vector<uint32_t> vector2;

        for (Vector<uint32_t>::ConstIterator iter = constVector.begin(); iter != constVector.end(); ++iter)
        {
            vector2.push_back(*iter);
        }

        EXPECT_EQ(2u, vector2.size());
        EXPECT_EQ(42u, vector2[0]);
        EXPECT_EQ(47u, vector2[1]);
    }

    TEST_F(VectorTest, IteratorOnConstVectorWithInitialCapacityAndValues)
    {
        Vector<uint32_t> vector(12, 55u);

        const Vector<uint32_t>& constVector = vector;

        Vector<uint32_t> vector2;

        for (Vector<uint32_t>::ConstIterator iter = constVector.begin(); iter != constVector.end(); ++iter)
        {
            vector2.push_back(*iter);
        }

        EXPECT_EQ(12u, vector2.size());
        EXPECT_EQ(55u, vector2[0]);
        EXPECT_EQ(55u, vector2[1]);
        EXPECT_EQ(55u, vector2[2]);
        EXPECT_EQ(55u, vector2[3]);
        EXPECT_EQ(55u, vector2[4]);
        EXPECT_EQ(55u, vector2[5]);
        EXPECT_EQ(55u, vector2[6]);
        EXPECT_EQ(55u, vector2[7]);
        EXPECT_EQ(55u, vector2[8]);
        EXPECT_EQ(55u, vector2[9]);
        EXPECT_EQ(55u, vector2[10]);
        EXPECT_EQ(55u, vector2[11]);
    }

    TEST_F(VectorTest, AccessOperator)
    {
        Vector<uint32_t> vector;

        vector.push_back(42u);
        vector.push_back(47u);

        vector[0] = 47u;
        vector[1] = 42u;

        EXPECT_EQ(47u, vector[0]);
        EXPECT_EQ(42u, vector[1]);
    }

    struct TestStruct
    {
        uint32_t value1;
        float_t  value2;
    };

    TEST_F(VectorTest, Object)
    {
        Vector<TestStruct> vector;

        TestStruct struct1;
        struct1.value1 = 47;
        struct1.value2   = 11.f;

        TestStruct struct2;
        struct2.value1 = 8;
        struct2.value2 = 15.f;

        vector.push_back(struct1);
        vector.push_back(struct2);

        Vector<uint32_t> vector2;

        for (Vector<TestStruct>::Iterator iter = vector.begin(); iter != vector.end(); ++iter)
        {
            vector2.push_back(iter->value1);
        }

        EXPECT_EQ(47u, vector2[0]);
        EXPECT_EQ(8u, vector2[1]);
    }

    TEST_F(VectorTest, Resize)
    {
        Vector<uint32_t> vector(2);

        vector.push_back(1);
        vector.push_back(2);

        vector.resize(19);

        EXPECT_EQ(1u, vector[0]);
        EXPECT_EQ(2u, vector[1]);

        vector.resize(1);

        EXPECT_EQ(1u, vector[0]);
    }

    TEST_F(VectorTest, Clear)
    {
        TestStruct struct1;
        struct1.value1 = 47;
        struct1.value2   = 11.f;

        TestStruct struct2;
        struct2.value1 = 8;
        struct2.value2 = 15.f;


        Vector<TestStruct> vector;

        vector.push_back(struct1);
        vector.push_back(struct2);

        vector.clear();

        vector.push_back(struct2);
        vector.push_back(struct1);

        EXPECT_EQ(struct2.value1, vector[0].value1);
        EXPECT_EQ(struct2.value2, vector[0].value2);
        EXPECT_EQ(struct1.value1, vector[1].value1);
        EXPECT_EQ(struct1.value2, vector[1].value2);

    }

    TEST_F(VectorTest, EraseIterator)
    {
        Vector<uint32_t> vector;

        vector.push_back(1u);
        vector.push_back(2u);
        vector.push_back(3u);
        vector.push_back(4u);
        vector.push_back(5u);

        Vector<uint32_t>::Iterator iter = vector.begin();

        EXPECT_EQ(capu::CAPU_EINVAL, vector.erase(iter + 8u));

        vector.erase(iter + 2u);

        EXPECT_EQ(4u, vector.size());
        EXPECT_EQ(1u, vector[0]);
        EXPECT_EQ(2u, vector[1]);
        EXPECT_EQ(4u, vector[2]);
        EXPECT_EQ(5u, vector[3]);

        vector.erase(vector.begin());

        EXPECT_EQ(3u, vector.size());
        EXPECT_EQ(2u, vector[0]);
        EXPECT_EQ(4u, vector[1]);
        EXPECT_EQ(5u, vector[2]);

        vector.erase(vector.end() - 1u);

        EXPECT_EQ(2u, vector.size());
        EXPECT_EQ(2u, vector[0]);
        EXPECT_EQ(4u, vector[1]);

        vector.erase(vector.begin());
        vector.erase(vector.begin());

        EXPECT_EQ(0u, vector.size());
    }

    TEST_F(VectorTest, EraseIndex)
    {
        Vector<uint32_t> vector;

        vector.push_back(1u);
        vector.push_back(2u);
        vector.push_back(3u);
        vector.push_back(4u);
        vector.push_back(5u);

        Vector<uint32_t>::Iterator iter = vector.begin();

        ++iter;
        ++iter;

        status_t result = vector.erase(iter);

        EXPECT_TRUE(CAPU_OK == result);
        EXPECT_EQ(4u, vector.size());
        EXPECT_EQ(1u, vector[0]);
        EXPECT_EQ(2u, vector[1]);
        EXPECT_EQ(4u, vector[2]);
        EXPECT_EQ(5u, vector[3]);

        result = vector.erase(vector.begin());

        EXPECT_TRUE(CAPU_OK == result);
        EXPECT_EQ(3u, vector.size());
        EXPECT_EQ(2u, vector[0]);
        EXPECT_EQ(4u, vector[1]);
        EXPECT_EQ(5u, vector[2]);

        iter = vector.end();

        result = vector.erase(iter);

        EXPECT_FALSE(CAPU_OK == result);
        EXPECT_EQ(3u, vector.size());
        EXPECT_EQ(2u, vector[0]);
        EXPECT_EQ(4u, vector[1]);
        EXPECT_EQ(5u, vector[2]);

        --iter;

        result = vector.erase(iter);

        EXPECT_TRUE(CAPU_OK == result);
        EXPECT_EQ(2u, vector.size());
        EXPECT_EQ(2u, vector[0]);
        EXPECT_EQ(4u, vector[1]);

        result = vector.erase(vector.begin());

        EXPECT_TRUE(CAPU_OK == result);

        result = vector.erase(vector.begin());

        EXPECT_TRUE(CAPU_OK == result);
        EXPECT_EQ(0u, vector.size());
    }

    TEST_F(VectorTest, EraseWithElementOld)
    {
        Vector<uint32_t> vector;

        vector.push_back(1u);
        vector.push_back(2u);
        vector.push_back(3u);
        vector.push_back(4u);
        vector.push_back(5u);

        uint32_t old;

        vector.erase(vector.begin(), &old);
        EXPECT_EQ(old, 1u);

        vector.erase(vector.begin()+2u, &old);
        EXPECT_EQ(old, 4u);
    }

    TEST_F(VectorTest, EraseAdd)
    {
        Vector<uint32_t> vector;

        vector.push_back(1u);
        vector.push_back(2u);
        vector.push_back(3u);
        vector.push_back(4u);
        vector.push_back(5u);

        vector.erase(3);
        vector.erase(1);
        vector.push_back(2u);
        vector.push_back(4u);

        EXPECT_EQ(5u, vector.size());
        EXPECT_EQ(1u, vector[0]);
        EXPECT_EQ(3u, vector[1]);
        EXPECT_EQ(5u, vector[2]);
        EXPECT_EQ(2u, vector[3]);
        EXPECT_EQ(4u, vector[4]);
    }
    TEST_F(VectorTest, ForEach)
    {
        capu::Vector<capu::int32_t> vector;

        vector.push_back(32);
        vector.push_back(43);
        vector.push_back(44);

        capu::Vector<capu::int32_t> testVector;

        capu_foreach(capu::Vector<capu::int32_t>, vector, iter)
        {
            testVector.push_back(*iter);
        }

        EXPECT_EQ(32, testVector[0]);
        EXPECT_EQ(43, testVector[1]);
        EXPECT_EQ(44, testVector[2]);

    }

    
    TEST_F(VectorTest, Compare)
    {
        Vector<uint32_t> vector1;
        Vector<uint32_t> vector2;
        Vector<uint32_t> vector3;

        vector1.push_back(1);
        vector1.push_back(2);
        vector1.push_back(3);

        vector2.push_back(1);
        vector2.push_back(2);
        vector2.push_back(2);

        EXPECT_FALSE(vector1 == vector2);

        vector2[2] = 3;
        
        EXPECT_TRUE(vector1 == vector2);

        EXPECT_FALSE(vector3 == vector2);
    
    }

    TEST_F(VectorTest, CompareComplexType)
    {
        Vector<String> vector1;
        Vector<String> vector2;
        Vector<String> vector3;

        vector1.push_back("test");
        vector2.push_back("something");

        EXPECT_FALSE(vector1 == vector2);

        vector2.clear();
        vector2.push_back("test");

        EXPECT_TRUE(vector1 ==  vector2);

        EXPECT_FALSE(vector3 == vector2);

    }
}
