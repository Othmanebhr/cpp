#include "../includes/Serializer.hpp"

int main()
{
	Data Sana(99, "Elle lave Maxime en code c'est trop grave");

	/*Data originale*/
	std::cout << "Données originales:" << std::endl;
	std::cout << "Nombre: " << Sana.nb << std::endl;
	std::cout << "Texte: " << Sana.str << std::endl;
	std::cout << "Adresse: " << &Sana << std::endl;

	uintptr_t test = Serializer::serialize(&Sana);
	std::cout << "Valeur sérialisée (uintptr_t): " << test << std::endl;
	
	// Désérialiser et afficher l'adresse obtenue
	Data *test2 = Serializer::deserialize(test);
	std::cout << "Adresse désérialisée: " << test2 << std::endl;
	
	// Afficher les données à travers le pointeur désérialisé
	std::cout << "\nDonnées via pointeur désérialisé:" << std::endl;
	std::cout << "Nombre: " << test2->nb << std::endl;
	std::cout << "Texte: " << test2->str << std::endl;

	// Vérifier si les adresses sont identiques
	if (&Sana == test2)
		std::cout << "\nLes adresses sont identiques. OK" << std::endl;
	else
		std::cout << "\nLes adresses sont différentes. KO!" << std::endl;
}