#pragma once
#include <locale>
#include <vector>
#include <time.h>


namespace {

    double prob(int num, std::vector<int> arr) {
        double sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum = sum + arr[i];
        }
        return (double)(num / sum);
    }

    int _toDecimal(std::string s) {
        int dec = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') dec += pow(2, s.size() - (i + 1));
        }
        return dec;
    }

    std::string _toBinary(int n) {
        std::string r = "";
        while (n != 0) {
            r = (n % 2 == 0 ? '0' : '1') + r;
            n /= 2;
        }
        while (r.size() != 8) {
            r = '0' + r;
        }
        return r;
    }

    std::vector<int> toDecimal(std::vector<std::string> bin_arr) {
        std::vector<int> aux;
        for (int i = 0; i < bin_arr.size(); i++) {
            aux.push_back(_toDecimal(bin_arr[i]));
        }
        return aux;
    }

    std::vector<std::string> toBinary(std::vector<int> arr) {
        std::vector<std::string> bin_aux;
        for (int i = 0; i < arr.size(); i++) {
            bin_aux.push_back(_toBinary(arr[i]));
        }
        return bin_aux;
    }

    int random_prob(double prob1, double prob2, double prob3) {
        double val = (double)rand() / RAND_MAX;
        int random;
        if (val < prob1)
            random = 0;
        else if (val < prob1 + prob2)
            random = 1;
        else if (val < prob1 + prob2 + prob3)
            random = 2;
        else
            random = 3;
        return random;
    }

    void imprimir(std::vector<int> arr, std::vector<std::string> bin_arr) {
        for (int i = 0; i < arr.size(); i++) {
            std::cout << "[" << i << "]\t" << arr[i] << "\t" << bin_arr[i] << std::endl;
        }
        std::cout << std::endl;
    }

    std::string cruzar(std::string s1, std::string s2, int punto) {
        std::string s = "";
        for (int i = 0; i < punto; i++) {
            s += s1[i];
        }
        for (int i = punto; i < s2.size(); i++) {
            s += s2[i];
        }
        return s;
    }

    std::vector<int> alg_gen(std::vector<int> *stats)
    {
        srand(time(NULL));
        std::locale::global(std::locale("spanish"));
        //std::vector<int> arreglo = { 35, 86, 42, 74 };
        std::vector<int> arreglo = *stats;
        std::vector<int> aux = arreglo;
        std::vector<std::string> bin_arreglo = toBinary(arreglo);
        std::vector<std::string> bin_aux = bin_arreglo;
        int random;

        std::cout << "Original: " << std::endl;
        imprimir(arreglo, bin_arreglo);

        // 1. Selección

        for (int i = 0; i < arreglo.size(); i++) {
            aux[i] = arreglo[random_prob(prob(arreglo[0], arreglo), prob(arreglo[1], arreglo), prob(arreglo[2], arreglo))];
        }

        arreglo = aux;
        bin_arreglo = toBinary(arreglo);
        std::cout << "Selección: " << std::endl;
        imprimir(arreglo, bin_arreglo);

        // 2. Cruce
        random = rand() % 4;
        bin_aux[0] = cruzar(bin_arreglo[0], bin_arreglo[1], random);
        bin_aux[1] = cruzar(bin_arreglo[1], bin_arreglo[0], random);
        random = rand() % 4;
        bin_aux[2] = cruzar(bin_arreglo[2], bin_arreglo[3], random);
        bin_aux[3] = cruzar(bin_arreglo[3], bin_arreglo[2], random);

        bin_arreglo = bin_aux;
        arreglo = toDecimal(bin_arreglo);
        std::cout << "Cruce: " << std::endl;
        imprimir(arreglo, bin_arreglo);

        // 3. Mutación

        for (int i = 0; i < arreglo.size(); i++) {
            srand(time(NULL));
            random = rand() % bin_arreglo[i].size() + 1;
            if (random != bin_arreglo[i].size()) {
                if (random > 4) {
                    if (bin_arreglo[i][random] == '0') bin_arreglo[i][random] = '1';
                    else bin_arreglo[i][random] = '0';
                }
            }
        }
        arreglo = toDecimal(bin_arreglo);
        std::cout << "Mutación: " << std::endl;
        imprimir(arreglo, bin_arreglo);

        return arreglo;
    }
}
