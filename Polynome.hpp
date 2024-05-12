#include <vector>
using std::vector;

/**
 * @brief Represents a polynomial with coefficients.
 *
 * The Polynome class allows for the creation, manipulation, and evaluation of polynomials.
 * Each polynomial is defined by its coefficients, stored in a vector.
 */


class Polynome
{
private:
    int order;                   ///< The order of the polynomial.
    vector<double> coefficients; ///< The coefficients of the polynomial.

public:
    /**
     * @brief Constructs a polynomial with given coefficients.
     *
     * @param A The coefficients of the polynomial in ascending order of powers.
     */
    Polynome(vector<double> A);
    /**
     * @brief Prints the polynomial equation.
     */
    void PrintEq();
    /**
     * @brief Gets the order of the polynomial.
     *
     * @return The order of the polynomial.
     */
    int GetOrder() { return this->order; };
    /**
     * @brief Gets the coefficient at the specified index.
     *
     * @param index The index of the coefficient to retrieve.
     * @return The coefficient at the specified index.
     */
    double GetCoef(int index) { return this->coefficients[index]; };

    /**
     * @brief Adds another polynomial to this polynomial.
     *
     * @param eq2 The polynomial to add.
     * @return The sum of the two polynomials.
     */
    Polynome AddEq(Polynome eq2);
    /**
     * @brief Subtracts another polynomial from this polynomial.
     * 
     * @param eq2 The polynomial to subtract.
     * @return The difference between the two polynomials.
     */
    Polynome SubstractEq(Polynome eq2);
    /**
     * @brief Calculates the value of the polynomial for a given input.
     * 
     * @param n The input value.
     * @return The result of evaluating the polynomial for the input value.
     */
    double CalculateEq(double n);
    /**
     * @brief Computes the derivative of the polynomial.
     * 
     * @return The derivative of the polynomial.
     */
    Polynome DeriveEq();
    /**
     * @brief Computes the indefinite integral of the polynomial.
     * 
     * @return The indefinite integral of the polynomial.
     */
    Polynome IntegrateEq();
};