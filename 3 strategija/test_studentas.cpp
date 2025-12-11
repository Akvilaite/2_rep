/**
 * @file test_studentas.cpp
 * @brief Unit testai Studentas klasei naudojant Google Test framework
 * @author Jūsų vardas
 * @date 2024
 */

#include <gtest/gtest.h>
#include "studentas.h"
#include <sstream>

 /**
  * @brief Test fixture klasė studentų testams
  */
class StudentasTest : public ::testing::Test {
protected:
    Studentas stud;

    void SetUp() override {
        // Paruošiamas studentas testams
        stud.setVar("Jonas");
        stud.setPav("Jonaitis");
    }
};

/**
 * @test Testuoja numatytąjį konstruktorių
 */
TEST_F(StudentasTest, DefaultConstructor) {
    Studentas s;
    EXPECT_EQ(s.var(), "");
    EXPECT_EQ(s.pav(), "");
    EXPECT_EQ(s.egz(), 0);
    EXPECT_EQ(s.galVid(), 0.0);
    EXPECT_EQ(s.galMed(), 0.0);
}

/**
 * @test Testuoja setter ir getter metodus
 */
TEST_F(StudentasTest, SettersAndGetters) {
    stud.setVar("Petras");
    stud.setPav("Petraitis");
    stud.setEgz(8);

    EXPECT_EQ(stud.var(), "Petras");
    EXPECT_EQ(stud.pav(), "Petraitis");
    EXPECT_EQ(stud.egz(), 8);
}

/**
 * @test Testuoja pažymių nustatymą
 */
TEST_F(StudentasTest, SetPazymiai) {
    std::vector<int> paz = { 8, 9, 7, 10 };
    stud.setPaz(paz);

    EXPECT_EQ(stud.paz().size(), 4);
    EXPECT_EQ(stud.paz()[0], 8);
    EXPECT_EQ(stud.paz()[3], 10);
}

/**
 * @test Testuoja galutinio vidurkio skaičiavimą
 */
TEST_F(StudentasTest, ComputeGalutinisVidurkis) {
    std::vector<int> paz = { 8, 9, 10 }; // vidurkis = 9
    stud.setPaz(paz);
    stud.setEgz(10);
    stud.computeGalutiniai();

    // 0.4 * 9 + 0.6 * 10 = 3.6 + 6.0 = 9.6
    EXPECT_NEAR(stud.galVid(), 9.6, 0.01);
}

/**
 * @test Testuoja galutinės medianos skaičiavimą su nelyginiu skaičiumi
 */
TEST_F(StudentasTest, ComputeGalutinisMedianaOdd) {
    std::vector<int> paz = { 7, 8, 9 }; // mediana = 8
    stud.setPaz(paz);
    stud.setEgz(10);
    stud.computeGalutiniai();

    // 0.4 * 8 + 0.6 * 10 = 3.2 + 6.0 = 9.2
    EXPECT_NEAR(stud.galMed(), 9.2, 0.01);
}

/**
 * @test Testuoja galutinės medianos skaičiavimą su lyginiu skaičiumi
 */
TEST_F(StudentasTest, ComputeGalutinisMedianaEven) {
    std::vector<int> paz = { 6, 8, 9, 10 }; // mediana = (8+9)/2 = 8.5
    stud.setPaz(paz);
    stud.setEgz(10);
    stud.computeGalutiniai();

    // 0.4 * 8.5 + 0.6 * 10 = 3.4 + 6.0 = 9.4
    EXPECT_NEAR(stud.galMed(), 9.4, 0.01);
}

/**
 * @test Testuoja atvejį, kai nėra namų darbų pažymių
 */
TEST_F(StudentasTest, ComputeGalutinisBeND) {
    std::vector<int> paz = {};
    stud.setPaz(paz);
    stud.setEgz(8);
    stud.computeGalutiniai();

    // Kai nėra ND, galutinis = egzaminas
    EXPECT_EQ(stud.galVid(), 8.0);
    EXPECT_EQ(stud.galMed(), 8.0);
}

/**
 * @test Testuoja kopijavimo konstruktorių
 */
TEST_F(StudentasTest, CopyConstructor) {
    std::vector<int> paz = { 8, 9, 10 };
    stud.setPaz(paz);
    stud.setEgz(9);
    stud.computeGalutiniai();

    Studentas kopija(stud);

    EXPECT_EQ(kopija.var(), stud.var());
    EXPECT_EQ(kopija.pav(), stud.pav());
    EXPECT_EQ(kopija.egz(), stud.egz());
    EXPECT_EQ(kopija.galVid(), stud.galVid());
    EXPECT_EQ(kopija.galMed(), stud.galMed());
    EXPECT_EQ(kopija.paz().size(), stud.paz().size());
}

/**
 * @test Testuoja priskyrimo operatorių
 */
TEST_F(StudentasTest, AssignmentOperator) {
    std::vector<int> paz = { 7, 8, 9 };
    stud.setPaz(paz);
    stud.setEgz(10);
    stud.computeGalutiniai();

    Studentas kitas;
    kitas = stud;

    EXPECT_EQ(kitas.var(), stud.var());
    EXPECT_EQ(kitas.pav(), stud.pav());
    EXPECT_EQ(kitas.egz(), stud.egz());
}

/**
 * @test Testuoja palyginimo operatorių (<)
 */
TEST_F(StudentasTest, ComparisonOperatorLess) {
    Studentas s1, s2;
    s1.setVar("Agne");
    s1.setPav("Agnaite");
    s2.setVar("Bronius");
    s2.setPav("Broniauskas");

    EXPECT_TRUE(s1 < s2);  // Agne < Bronius (pagal pavardę)
    EXPECT_FALSE(s2 < s1);
}

/**
 * @test Testuoja palyginimo operatorių su vienoda pavarde
 */
TEST_F(StudentasTest, ComparisonOperatorSameSurname) {
    Studentas s1, s2;
    s1.setVar("Agne");
    s1.setPav("Petraitis");
    s2.setVar("Bronius");
    s2.setPav("Petraitis");

    EXPECT_TRUE(s1 < s2);  // Agne < Bronius (pagal vardą)
}

/**
 * @test Testuoja lygybės operatorių
 */
TEST_F(StudentasTest, EqualityOperator) {
    Studentas s1, s2;
    s1.setVar("Jonas");
    s1.setPav("Jonaitis");
    s2.setVar("Jonas");
    s2.setPav("Jonaitis");

    EXPECT_TRUE(s1 == s2);

    s2.setVar("Petras");
    EXPECT_FALSE(s1 == s2);
}

/**
 * @test Testuoja duomenų nuskaitymą iš srauto
 */
TEST_F(StudentasTest, ReadFromStream) {
    std::istringstream iss("Jonas Jonaitis 8 9 7 10");
    Studentas s;
    iss >> s;

    EXPECT_EQ(s.var(), "Jonas");
    EXPECT_EQ(s.pav(), "Jonaitis");
    EXPECT_EQ(s.egz(), 10);  // paskutinis skaičius
    EXPECT_EQ(s.paz().size(), 3);  // 8, 9, 7
}

/**
 * @test Testuoja galutinio įvertinimo ribines reikšmes
 */
TEST_F(StudentasTest, BoundaryValues) {
    // Maksimalūs pažymiai
    std::vector<int> paz = { 10, 10, 10 };
    stud.setPaz(paz);
    stud.setEgz(10);
    stud.computeGalutiniai();

    EXPECT_NEAR(stud.galVid(), 10.0, 0.01);
    EXPECT_NEAR(stud.galMed(), 10.0, 0.01);

    // Minimalūs pažymiai
    paz = { 1, 1, 1 };
    stud.setPaz(paz);
    stud.setEgz(1);
    stud.computeGalutiniai();

    EXPECT_NEAR(stud.galVid(), 1.0, 0.01);
    EXPECT_NEAR(stud.galMed(), 1.0, 0.01);
}

/**
 * @test Testuoja "vargšiuko" klasifikaciją (< 5.0)
 */
TEST_F(StudentasTest, VargsiukasClassification) {
    std::vector<int> paz = { 3, 4, 3 };
    stud.setPaz(paz);
    stud.setEgz(4);
    stud.computeGalutiniai();

    EXPECT_LT(stud.galVid(), 5.0);  // Turėtų būti vargšiukas
}

/**
 * @test Testuoja "kietiako" klasifikaciją (>= 5.0)
 */
TEST_F(StudentasTest, KietiakasClassification) {
    std::vector<int> paz = { 8, 9, 7 };
    stud.setPaz(paz);
    stud.setEgz(8);
    stud.computeGalutiniai();

    EXPECT_GE(stud.galVid(), 5.0);  // Turėtų būti kietiakas
}

/**
 * @brief Pagrindinė test runner funkcija
 */
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}