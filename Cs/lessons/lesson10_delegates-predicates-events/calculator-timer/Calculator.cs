using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson10_2
{
    public class ResultEventAgs : EventArgs
    {
        public double Result { get; private set; }

        public ResultEventAgs(double result)
        {
            Result = result;
        }
    }

    public class Calculator
    {
        public event EventHandler<ResultEventAgs> ResultCalculated;
        public void Start()
        {
            var input = Console.ReadLine();
            input = input.Replace(" ", string.Empty);//удаляет пробелы из строки

            var signs = new[] { '+', '-', '*', '/' };

            var singIndex = input.IndexOfAny(signs);

            var a = double.Parse(input.Substring(0, singIndex));

            var b = double.Parse(input.Substring(singIndex + 1));

            Func<double, double, double> operation = null;

            switch (input[singIndex])
            {
                case '+':
                    operation = (x, y) => x + y;
                    break;
                case '-':
                    operation = (x, y) => x - y;
                    break;
                case '*':
                    operation = (x, y) => x * y;
                    break;
                case '/':
                    operation = (x, y) =>
                    {
                        if (y == 0)
                        {
                            throw new DivideByZeroException();
                        }
                        return x / y;
                    };
                    break;
            }

            var result = operation(a, b);
            OnResultCalculated(result);
        }

        private void OnResultCalculated(double result)
        {
            var handler = ResultCalculated;//handler указатель на функцию

            if (handler != null)
            {
                handler(this, new ResultEventAgs(result));
            }
        }
    }
}
