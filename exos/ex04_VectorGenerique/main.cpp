/*********
 *
 * But de l'exercice:
 *  - compiler et exécuter le programme.
 *  - prendre note de la sortie du programme - observer le comportement de la
 *sémantique de copie.
 *  - implémenter le constructeur de déplacemenent et l'affectation de
 *déplacement afine de compléter la règle des cinq.
 *  - prendre note de la sortie du programme - observer le comportement de la
 *sémantique de déplacement.
 *
 * Note: modifier uniquement la classe Vector, le programme de test en dessous
 * doit rester identique.
 *
 *************/

#include <algorithm>
#include <cstddef>
#include <string>
#include <iostream>
#include <utility>

/**
 * @brief Classe représentant un vecteur de n-éléments avec un nom.
 *
 * Démontre la règle des trois et inclut un nom pour le vecteur.
 */
 template<typename T>
class Vector {
public:
    /**
     * @brief Construit un vecteur d'une taille donnée avec un nom.
     *
     * @param sz Taille du vecteur à créer.
     * @param name Nom du vecteur.
     */
    Vector(size_t sz, const std::string& name)
        : data_{new T[sz]{}}, sz_{sz}, name_{name} {
        std::cout << name_ << " : constructed" << std::endl;
    }

    Vector(std::initializer_list<T> args) : sz_{args.size()}, data_{new T[args.size()]} {
        size_t i = 0;
        for(T arg : args){
            data_[i++] = arg;
        }
    }

    /**
     * @brief Destructeur qui libère la mémoire allouée au vecteur.
     */
    ~Vector() {
        std::cout << name_ << " : destructed" << std::endl;
        delete[] data_;
    }

    /**
     * @brief Constructeur de copie qui crée une copie d'un vecteur existant, y
     * compris son nom.
     *
     * @param other Le vecteur à copier.
     */
    Vector(const Vector& other)
        : data_{new int[other.sz_]}, sz_{other.sz_}, name_{other.name_} {
        std::cout << name_ << " : copy constructed from: " << other.name_
                  << std::endl;
        std::copy(other.data_, other.data_ + other.sz_, data_);
    }

    /**
     * @brief Opérateur d'affectation qui copie le contenu d'un vecteur dans un
     * autre, y compris son nom. Utilise l'idiome "copy and swap" (other est
     * passé par copie).
     *
     * @param other Le vecteur à copier.
     * @return Vector& Référence au vecteur actuel après copie.
     */
    Vector& operator=(Vector other) {
        std::cout << name_ << " : assigned from " << other.name_ << std::endl;
        std::swap(data_, other.data_);
        std::swap(sz_, other.sz_);
        std::swap(name_, other.name_);
        return *this;
    }

    /**
     * @brief Accède à un élément du vecteur par son indice.
     *
     * @param index L'indice de l'élément à accéder.
     * @return int& Référence à l'élément à l'indice spécifié.
     */
    T& operator[](size_t index) { return data_[index]; }

    /**
     * @brief Accède à un élément du vecteur par son indice (version const).
     *
     * @param index L'indice de l'élément à accéder.
     * @return const int& Référence const à l'élément à l'indice spécifié.
     */
    const T& operator[](size_t index) const { return data_[index]; }

    /**
     * @brief Retourne la taille du vecteur.
     *
     * @return size_t La taille du vecteur.
     */
    size_t size() const { return sz_; }

    /**
     * @brief Retourne le nom du vecteur.
     *
     * @return const std::string& Le nom du vecteur.
     */
    const std::string& name() const { return name_; }


    /**
     * @brief Constructeur de déplacement
     */
    Vector(Vector&& other)
        : data_{std::exchange(other.data_, nullptr)},
          sz_{std::exchange(other.sz_, 0)},
          name_{std::move(other.name_)} {
                std::cout << name_ << " : moved-constructed from " << other.name_ << std::endl;
          }

    /**
     * @brief Opérateur d'affectation de déplacement
     */
    Vector& operator=(Vector&& other) {
        std::cout << name_ << " : moved-assigned from " << other.name_
            << std::endl;
        if (this != &other) {
            delete[] data_;
            data_ = std::exchange(other.data_, nullptr);
            sz_ = std::exchange(other.sz_, 0);
            name_ = std::move(other.name_);
        }
        return *this;
    }

private:
    T* data_;  ///< Pointeur vers le tableau contenant les éléments du
                 ///< vecteur.
    size_t sz_;  ///< Taille du vecteur.
    std::string name_;  ///< Nom du vecteur.
};

// ***************** Ne pas éditer le code de test ci dessous ******************
// 
#include <type_traits>

int main() {
    Vector<int> v = {1, 3, 5};
    Vector<double> a{2.3, 4., 5.6, 8.11};

}