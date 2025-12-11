# ============================================
# Makefile - Studentų Valdymo Sistema v2.0
# ============================================

# Kompiliatorius ir flagų nustatymai
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -O2

# Programos pavadinimas
TARGET = programa

# Source failai (PAKEISKITE pagal savo failus)
SOURCES = main.cpp studentas.cpp failai.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Header failai
HEADERS = studentas.h zmogus.h failai.h rusiavimas.h

# Testų failai
TEST_TARGET = programa_tests
TEST_SOURCES = test_studentas.cpp studentas.cpp failai.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

# Google Test bibliotekos (jei įdiegtos sistemoje)
# Jei neturite, komentuokite šias eilutes ir naudokite tik CMake testams
TEST_LIBS = -lgtest -lgtest_main -lpthread

# ============================================
# PAGRINDINIAI TIKSLAI
# ============================================

# Numatytasis tikslas - sukompiliuoti programą
all: $(TARGET)
	@echo "✅ Kompiliavimas baigtas!"
	@echo "Paleiskite: ./$(TARGET)"

# Kompiliuoti pagrindinę programą
$(TARGET): $(OBJECTS)
	@echo "🔗 Linkinami failai..."
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "✅ Programa sukurta: $(TARGET)"

# Kompiliuoti objektinius failus
%.o: %.cpp $(HEADERS)
	@echo "🔨 Kompiliuojama: $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ============================================
# TESTAI
# ============================================

# Kompiliuoti ir paleisti testus
test: $(TEST_TARGET)
	@echo ""
	@echo "🧪 Paleidžiami testai..."
	@echo "================================"
	./$(TEST_TARGET)
	@echo "================================"

# Kompiliuoti testų programą
$(TEST_TARGET): $(TEST_OBJECTS)
	@echo "🔗 Kompiliuojami testai..."
	@if command -v g++ >/dev/null 2>&1; then \
		$(CXX) $(CXXFLAGS) -o $@ $^ $(TEST_LIBS) 2>/dev/null || \
		(echo "⚠️  Google Test nerastas. Naudokite CMake testams:" && \
		 echo "   mkdir build && cd build" && \
		 echo "   cmake .. -DBUILD_TESTS=ON" && \
		 echo "   cmake --build ." && \
		 echo "   ctest" && \
		 exit 1); \
	fi
	@echo "✅ Testai sukompiliuoti: $(TEST_TARGET)"

# Kompiliuoti test objektinius failus
test_studentas.o: test_studentas.cpp $(HEADERS)
	@echo "🔨 Kompiliuojami testai: $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@ 2>/dev/null || \
		(echo "⚠️  Nepavyko kompiliuoti testų. Naudokite CMake." && exit 1)

# ============================================
# DOKUMENTACIJA
# ============================================

# Generuoti Doxygen dokumentaciją
doc:
	@echo "📚 Generuojama dokumentacija..."
	@if command -v doxygen >/dev/null 2>&1; then \
		doxygen Doxyfile && \
		echo "✅ Dokumentacija sukurta: doxygen/html/index.html" && \
		echo "Atidaryti: firefox doxygen/html/index.html"; \
	else \
		echo "❌ Doxygen nerastas!"; \
		echo "Įdiekite: sudo apt-get install doxygen graphviz"; \
		exit 1; \
	fi

# Atidaryti dokumentaciją naršyklėje
doc-open: doc
	@if [ -f doxygen/html/index.html ]; then \
		xdg-open doxygen/html/index.html 2>/dev/null || \
		open doxygen/html/index.html 2>/dev/null || \
		firefox doxygen/html/index.html 2>/dev/null || \
		echo "Atidaryti rankiniu būdu: doxygen/html/index.html"; \
	fi

# ============================================
# VALYMAS
# ============================================

# Išvalyti kompiliuotus failus
clean:
	@echo "🧹 Valoma..."
	rm -f $(OBJECTS) $(TEST_OBJECTS)
	rm -f $(TARGET) $(TEST_TARGET)
	rm -f *.o
	@echo "✅ Objektiniai failai išvalyti"

# Išvalyti viską (su dokumentacija ir rezultatais)
clean-all: clean
	@echo "🧹 Trinama visa..."
	rm -rf doxygen/
	rm -f *.txt
	rm -f stud*.txt vargsiukai.txt
	@echo "✅ Viskas išvalyta"

# ============================================
# PAGALBA IR NAUDINGOS KOMANDOS
# ============================================

# Parodyti pagalbą
help:
	@echo "=========================================="
	@echo "Studentų Valdymo Sistema v2.0 - Makefile"
	@echo "=========================================="
	@echo ""
	@echo "📌 PAGRINDINIAI TIKSLAI:"
	@echo "  make              - Kompiliuoti programą"
	@echo "  make all          - Tas pats kaip 'make'"
	@echo "  make test         - Kompiliuoti ir paleisti testus"
	@echo "  make doc          - Generuoti dokumentaciją"
	@echo "  make doc-open     - Generuoti ir atidaryti dokumentaciją"
	@echo "  make clean        - Ištrinti kompiliuotus failus"
	@echo "  make clean-all    - Ištrinti viską"
	@echo "  make help         - Parodyti šią pagalbą"
	@echo ""
	@echo "📌 NAUDOJIMO PAVYZDŽIAI:"
	@echo "  make && ./$(TARGET)           - Kompiliuoti ir paleisti"
	@echo "  make test                      - Paleisti testus"
	@echo "  make doc                       - Sukurti dokumentaciją"
	@echo "  make clean && make             - Perprogramuoti nuo nulio"
	@echo ""
	@echo "📌 REIKALAVIMAI:"
	@echo "  - g++ su C++17 palaikymu"
	@echo "  - Google Test (testams, pasirinktinai)"
	@echo "  - Doxygen (dokumentacijai, pasirinktinai)"
	@echo ""

# Paleisti programą po kompiliavimo
run: $(TARGET)
	@echo ""
	@echo "🚀 Paleidžiama programa..."
	@echo "================================"
	./$(TARGET)

# Kompiliuoti ir iš karto paleisti
quick: clean all run

# Patikrinti failų struktūrą
check:
	@echo "📋 Tikrinami failai..."
	@echo ""
	@echo "Source failai:"
	@ls -1 *.cpp 2>/dev/null || echo "  ❌ .cpp failų nerasta"
	@echo ""
	@echo "Header failai:"
	@ls -1 *.h 2>/dev/null || echo "  ❌ .h failų nerasta"
	@echo ""
	@echo "Build sistema:"
	@ls -1 Makefile CMakeLists.txt 2>/dev/null || echo "  ⚠️  Build failų nerasta"
	@echo ""
	@echo "Dokumentacija:"
	@ls -1 Doxyfile mainpage.dox 2>/dev/null || echo "  ⚠️  Doxygen failų nerasta"
	@echo ""

# Statistika
stats:
	@echo "📊 Kodo statistika:"
	@echo ""
	@echo "Source failų eilutės:"
	@wc -l *.cpp 2>/dev/null | tail -1 || echo "  N/A"
	@echo ""
	@echo "Header failų eilutės:"
	@wc -l *.h 2>/dev/null | tail -1 || echo "  N/A"
	@echo ""
	@echo "Bendrai eilučių:"
	@wc -l *.cpp *.h 2>/dev/null | tail -1 || echo "  N/A"

# ============================================
# PHONY TIKSLAI (nėra tikri failai)
# ============================================

.PHONY: all clean clean-all test doc doc-open help run quick check stats

# ============================================
# PASTABOS
# ============================================
# 
# 1. Jei Google Test neįdiegtas, naudokite CMake testams:
#    mkdir build && cd build
#    cmake .. -DBUILD_TESTS=ON
#    cmake --build .
#    ctest
#
# 2. Jei Doxygen neįdiegtas:
#    sudo apt-get install doxygen graphviz  # Linux
#    brew install doxygen graphviz          # macOS
#
# 3. Makefile jautrus tabuliacijai! Įsitikinkite, kad
#    komandos pradedamos TAB, ne tarpais.
#