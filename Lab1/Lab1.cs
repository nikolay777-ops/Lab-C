using System;
using System.Numerics;

namespace Lab1
{
    class Lab1 
    {
        private static int numberOfRoots = 0;

        static void Main(string[] args)
        {
            Complex[] roots = new Complex[3];
            equatationSolver(roots);

            Console.WriteLine("There is(are) {0} root(s)", numberOfRoots);
            for (int i = 0; i < numberOfRoots; ++i)
            {
                Console.WriteLine(roots[i]);
            }
        }

        static void equatationSolver(Complex[] roots)
        {
            //ax^3 + bx^2 + cx + d = 0
            double cubicСoef = getCoefficient('A');
            double squareСoef = getCoefficient('B');
            double linearСoef = getCoefficient('C');
            double zeroСoef = getCoefficient('D');

            if (cubicСoef != 0) 
            {
                //ax^3 + bx^2 + cx + d = 0
                cubicSolver(cubicСoef, squareСoef, linearСoef, zeroСoef, roots);
            }
            else if (cubicСoef == 0 && squareСoef != 0)
            {
                //ax^2 + bx + c = 0
                quadraticSolver(squareСoef, linearСoef, zeroСoef, roots);
            }
            else if (cubicСoef == 0 && squareСoef == 0 && linearСoef != 0)
            {
                //ax + b = 0
                linearSolver(linearСoef, zeroСoef, roots);
            }
            else
            {
                //a = 0
                zeroSolver(zeroСoef);
            }
        }

        static void cubicSolver(double cubicСoef, double squareСoef, double linearСoef,
                                double zeroСoef, Complex[] roots)
        {
            if (cubicСoef != 0 && squareСoef == 0 && linearСoef == 0 && zeroСoef == 0)
            {
                for (int i = 0; i < 3; ++i)
                {
                    roots[numberOfRoots++] = new Complex(0.0, 0.0);
                }
                return;
            }

            //Solution by Cardano's method, using a primitive cube root of unity 
            double squareRootOf3 = Math.Sqrt(3);
            Complex[] unityRoot = { new Complex(1, 0),
                                    new Complex(-0.5, -squareRootOf3 / 2.0),
                                    new Complex(-0.5, squareRootOf3 / 2.0) };

            //Assistants and deltas help to simplufy calculations
            double delta0 = squareСoef * squareСoef - 3 * cubicСoef * linearСoe
            double delta1 = 2 * squareСoef * squareСoef * squareСoef - 9 * cubicСoef * squareСoef * linearСoef +
                            27 * cubicСoef * cubicСoef * zeroСoef;

            Complex assistant = Complex.Pow(delta1 * delta1 - 4 * delta0 * delta0 * delta0, 0.5);

            Complex assistantC = Complex.Pow((delta1 + assistant) / 2, 1.0 / 3);

            for (int i = 0; i < 3; ++i)
            {
                Complex assistantInner = assistantC * unityRoot[i];
                roots[numberOfRoots++] = (-1.0 / 3 * cubicСoef *
                                         (squareСoef + assistantInner + delta0 / assistantInner));
            }
        }

        static void quadraticSolver(double squareСoef, double linearСoef, double zeroСoef, Complex[] roots)
        {
            double discriminant = linearСoef * linearСoef - 4 * squareСoef * zeroСoef;

            if (discriminant >= 0)
            {
                roots[numberOfRoots++] = new Complex((-linearСoef + Math.Pow(discriminant, 0.5))
                                               / 2.0 * squareСoef, 0);

                roots[numberOfRoots++] = new Complex((-linearСoef - Math.Pow(discriminant, 0.5))
                                               / 2.0 * squareСoef, 0);
            }
            else
            {
                roots[numberOfRoots++] = new Complex(-linearСoef / 2.0 * squareСoef,
                                                Math.Pow(-discriminant, 0.5) / 2.0 * squareСoef);

                roots[numberOfRoots++] = new Complex(-linearСoef / 2.0 * squareСoef,
                                                -Math.Pow(-discriminant, 0.5) / 2.0 * squareСoef);
            }
        }

        static void linearSolver(double linearСoef, double zeroСoef, Complex[] roots)
        {
            roots[numberOfRoots++] = new Complex(-zeroСoef / linearСoef, 0);
        }

        static void zeroSolver(double zeroСoef)
        {
            if (zeroСoef == 0)
            {
                Console.WriteLine("All coefficient are equal to zero, " +
                                  "so there are infinit solutions");
            }
            else
            {
                Console.WriteLine("All coefficient, except D, are equal to zero, " +
                                  "so there are no solutions");
            }
        }

        static double getCoefficient(char coef)
        {
            Console.WriteLine("Enter coefficient " + coef);
            double tempCoefficient;
            bool inputCheck = double.TryParse(Console.ReadLine(), out tempCoefficient);

            while (!inputCheck)
            {
                Console.WriteLine("Oops, wrong input, try again.");
                Console.WriteLine("Enter coefficient " + coef);
                inputCheck = double.TryParse(Console.ReadLine(), out tempCoefficient);
            }
            return tempCoefficient;
        }
    }
}
