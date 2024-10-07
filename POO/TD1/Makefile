# Nom de l'exécutable
TARGET = bin/my_program

# Dossier contenant les fichiers objets
OBJDIR = obj

# Dossier contenant les fichiers source
SRCDIR = src

# Dossier contenant les fichiers en-têtes
INCDIR = include

# Compilateur
CXX = g++

# Options du compilateur
CXXFLAGS = -Wall -Wextra -std=c++17 -I$(INCDIR)

# Fichiers sources
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Fichiers objets
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Règle par défaut (compilation et lien)
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $(TARGET))  # Crée le dossier bin si nécessaire
	@echo "Linking $(TARGET)..."
	$(CXX) $(OBJECTS) -o $(TARGET)
	@echo "Compilation terminée !"

# Règle pour compiler les fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyer les fichiers objets et l'exécutable
clean:
	@echo "Cleaning project..."
	@rm -rf $(OBJDIR)/*.o $(TARGET)
	@echo "Nettoyage terminé !"

# Pour nettoyer les fichiers objets uniquement
clean_objs:
	@echo "Cleaning object files..."
	@rm -rf $(OBJDIR)/*.o
	@echo "Fichiers objets nettoyés !"

# Règle phony (ne pas vérifier l'existence de ces fichiers)
.PHONY: all clean clean_objs
