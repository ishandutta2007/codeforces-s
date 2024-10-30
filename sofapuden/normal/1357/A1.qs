namespace Solution {

    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {    
        using (q = (Qubit[2])) {
            X(q[0]);
            X(q[1]);
            unitary(q);
            if(M(q[1]) == Zero){
                X(q[0]);
                return 0;
            }
            else{
                X(q[1]);
                return 1;
            }
        }
    }
}