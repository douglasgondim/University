// Jose Douglas Gondim Soares - 485347

import java.util.*;

class Main {
    public static void main(String[] args) {
        Stm prog = new CompoundStm(new AssignStm("a",

                new OpExp(new NumExp(5),

                        OpExp.Plus, new NumExp(3))),

                new CompoundStm(
                        new AssignStm("b",
                                new EseqExp(
                                        new PrintStm(new PairExpList(new IdExp("a"),
                                                new LastExpList(
                                                        new OpExp(new IdExp("a"), OpExp.Minus, new NumExp(1))))),

                                        new OpExp(new NumExp(10), OpExp.Times,

                                                new IdExp("a")))),

                        new PrintStm(new LastExpList(new IdExp("b")))));
        Interpreter eva = new Interpreter();

        eva.eval(prog);

    }
}

class Interpreter {
    Hashtable<String, Integer> variables = new Hashtable<String, Integer>();

    void eval(Stm stm) {
        if (stm instanceof AssignStm)
            eval((AssignStm) stm);
        else if (stm instanceof PrintStm)
            eval((PrintStm) stm);
        else if (stm instanceof CompoundStm)
            eval((CompoundStm) stm);

    }

    void eval(AssignStm stm) {
        variables.put(stm.id, eval(stm.exp));
    }

    void eval(CompoundStm stm) {
        eval(stm.stm1);
        eval(stm.stm2);
    }

    void eval(PrintStm stm) {
        System.out.println(eval(stm.exps));

    }

    int eval(Exp exp) {
        if (exp instanceof NumExp)
            return eval((NumExp) exp);
        else if (exp instanceof IdExp)
            return eval((IdExp) exp);
        else if (exp instanceof OpExp)
            return eval((OpExp) exp);
        else if (exp instanceof EseqExp)
            return eval((EseqExp) exp);
        throw new ArithmeticException("Invalid Expression evaluation.");

    }

    int eval(NumExp exp) {
        return exp.num;

    }

    int eval(IdExp exp) {
        if (variables.get(exp.id) == null)
            throw new ArithmeticException("Undeclared Variable " + exp.id);
        ;
        int variableValue = variables.get(exp.id);
        return variableValue;
    }

    int eval(EseqExp exp) {
        eval(exp.stm);
        return eval(exp.exp);
    }

    int eval(OpExp exp) {
        switch (exp.oper) {
            case 1:
                return eval(exp.left) + eval(exp.right);
            case 2:
                return eval(exp.left) - eval(exp.right);
            case 3:
                return eval(exp.left) * eval(exp.right);
            case 4:
                return eval(exp.left) / eval(exp.right);
            default:
                throw new ArithmeticException("Invalid operation on expression.");
        }

    }

    String eval(ExpList exp) {
        if (exp instanceof PairExpList)
            return eval((PairExpList) exp);
        else if (exp instanceof LastExpList)
            return eval((LastExpList) exp);
        throw new ArithmeticException("Invalid expression list.");
    }

    String eval(LastExpList expList) {
        return String.valueOf(eval(expList.head));

    }

    String eval(PairExpList expList) {

        return String.valueOf(eval(expList.head)) + ' ' + String.valueOf(eval(expList.tail));

    }

}

abstract class Stm {
}

class CompoundStm extends Stm {
    Stm stm1, stm2;

    CompoundStm(Stm s1, Stm s2) {
        stm1 = s1;
        stm2 = s2;
    }
}

class AssignStm extends Stm {
    String id;
    public Exp exp;

    AssignStm(String i, Exp e) {
        id = i;
        exp = e;
    }
}

class PrintStm extends Stm {
    ExpList exps;

    PrintStm(ExpList e) {
        exps = e;
    }
}

abstract class Exp {
}

class IdExp extends Exp {
    String id;

    IdExp(String i) {
        id = i;
    }
}

class NumExp extends Exp {
    int num;

    NumExp(int n) {
        num = n;
    }

}

class OpExp extends Exp {
    Exp left, right;
    public int oper;
    final public static int Plus = 1, Minus = 2, Times = 3, Div = 4;

    OpExp(Exp l, int o, Exp r) {
        left = l;
        oper = o;
        right = r;
    }
}

class EseqExp extends Exp {
    Stm stm;
    public Exp exp;

    EseqExp(Stm s, Exp e) {
        stm = s;
        exp = e;
    }
}

abstract class ExpList {
}

class PairExpList extends ExpList {
    Exp head;
    public ExpList tail;

    PairExpList(Exp h, ExpList t) {
        head = h;
        tail = t;
    }
}

class LastExpList extends ExpList {
    Exp head;

    LastExpList(Exp h) {
        head = h;
    }
}
