public class Calculation {
    int operandFirst;
    double operandSecond;
    String upperCaseString;

    public void addIntegers(int operandFirst, int operandSecond) {
        int sum = operandFirst + operandSecond;
        System.out.println("Sum: " + sum);
    }

    public void convertToUppercase(String inputString) {
        upperCaseString = inputString.toUpperCase();
        System.out.println("Updated String: " + upperCaseString);
    }
}

public class MainProgram {
    public static void main(String[] args) {
        Calculation calculator = new Calculation();
        calculator.operandFirst = 10;
        calculator.operandSecond = 20.5;
        calculator.upperCaseString = "hello";
        
        calculator.addAndPrintResult(calculator.operandFirst, 5);
        calculator.updateAndPrintUppercase("world");
    }
}
