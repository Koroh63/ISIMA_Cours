-- Pour ce TP, nous travaillerons sous PostgreSQL.

/* *********************************
        Niveau débutant :
************************************ */

-- Sélection, projection, tri
-- 1-Donner les références des produits.
-- 59 lignes

select ref_produit 
from produits;

-- 2-Donner le code et la société des clients.
-- 38 lignes
select code_client,societe 
from clients;

-- 3-Donner le code des clients qui ont commandé des produits.
-- 37 lignes
select distinct code_client 
from commandes;
	
-- 4-Donner la référence des produits de la commande n°10254.
-- 1 ligne : 74
SELECT ref_produit 
FROM  details_commandes 
WHERE no_commande='10254';

-- 5-Donner le nom et la catégorie des sociétés lyonnaises ou nantaises de catégorie supérieure ou égale à 2. Triez-les par catégorie.
-- 3 lignes
SELECT clients.societe, clients.categorie  
FROM clients
WHERE ville IN ('Nantes','Lyon') AND clients.categorie >= 2 
ORDER BY categorie;

-- 6-Donner la liste des produits triée par prix décroissant puis par nom croissant.
-- 59 lignes
SELECT p.nom_produit ,p.prix_unitaire 
FROM produits p 
ORDER BY p.prix_unitaire DESC, p.nom_produit ASC

-- 7-Afficher les informations des sociétés dont le nom commence par C.
-- 3 lignes
SELECT * FROM clients c WHERE societe LIKE 'C%'

-- Opérateurs ensemblistes
-- 8-Donner la référence des produits dont le nom contient 'Sauce'
-- ou qui ont été commandé avec une quantité comprise entre 50 et 60.
-- (union)
-- 3 lignes
SELECT p.ref_produit FROM produits p WHERE p.nom_produit LIKE '%Sauce%'
UNION 
SELECT dc.ref_produit FROM details_commandes dc WHERE dc.quantite > 50 AND dc.quantite < 60


-- 9-Donner le code des clients qui n'ont pas commandé. 	
-- (différence ou NOT IN)
-- 1 ligne : FISSA
-- Dépend du SGBD (EXCEPT) :
SELECT c.code_client 
FROM clients c 
EXCEPT 
SELECT c.code_client
FROM commandes c 

SELECT c.code_client 
FROM clients c 
WHERE c.code_client NOT IN (
SELECT c.code_client
FROM commandes c) 

-- 10-Donner la référence des commandes du 2009-10-29 et qui ont commandé le produit 21. 
-- (intersection ou IN)
-- 2 lignes
SELECT c.no_commande 
FROM commandes c 
WHERE c.date_commande = '2009-10-29' 
	AND c.no_commande IN (SELECT no_commande FROM details_commandes dc WHERE dc.ref_produit = 21);

-- Jointures :
-- 11-Donner pour chaque commande, son numéro, sa date ainsi que la société, le pays et la catégorie du client. 
-- 339 lignes
SELECT c.no_commande,c.date_commande, c2.societe , c2.pays, c2.categorie
FROM commandes c 
JOIN clients c2 
ON c2.code_client = c.code_client

-- 12-Donner la date, le code, la société, le pays et la catégorie du client de la commande n°10258.
-- 1 ligne
SELECT c.date_commande,c.no_commande , c2.societe , c2.pays, c2.categorie
FROM commandes c 
JOIN clients c2 
ON c2.code_client = c.code_client
WHERE c.no_commande ='10258'


-- 13-Donner la référence, le prix unitaire, la quantité et le montant total (prix*quantité) des produits de la commande n°10258. 
-- 3 lignes
SELECT p.ref_produit,p.prix_unitaire,dc.quantite, (p.prix_unitaire *dc.quantite) AS montant_total
FROM commandes c 
JOIN details_commandes dc ON c.no_commande = dc.no_commande
JOIN produits p ON p.ref_produit = dc.ref_produit

-- 14-Donner les références des produits commandés par des sociétés suisses.
-- 12 lignes
SELECT DISTINCT dc.ref_produit
FROM commandes c 
JOIN details_commandes dc ON c.no_commande = dc.no_commande
JOIN clients c2 ON c2.code_client = c.code_client
WHERE c2.pays = 'Suisse'

-- Agrégations
-- 15-Donner le nombre de clients français.
-- 1 ligne : 7
SELECT count(societe)
FROM clients c 
WHERE c.pays ='France'

-- 16-Donner le nombre de clients qui ont commandé des produits.
-- 1 ligne : 37
SELECT count(DISTINCT c.code_client)
FROM commandes c ;

-- 17-Donner le prix moyen des produits.
-- 1 ligne : 129.88

SELECT avg(p.prix_unitaire)
FROM produits p ;



/* *********************************
        Niveau intermédiaire :
************************************ */

-- 18-Donner les pays dans lesquels se trouvent des clients de catégorie 1 ou 2.
-- Trier-les par ordre alphabétique.
-- 11 lignes

SELECT DISTINCT c.pays
FROM clients c 
WHERE c.categorie IN (1,2)
ORDER BY c.pays ASC

-- 19-Donner la référence des commandes contenant les produits 30 ou 74.
-- 13 lignes

SELECT DISTINCT dc.no_commande
FROM details_commandes dc 
WHERE dc.ref_produit IN (30,74)

-- 20-Donner la référence des commandes contenant les produits 30 et 74.
-- 1 ligne : 10263

SELECT c.no_commande
FROM commandes c 
JOIN details_commandes dc ON c.no_commande = dc.no_commande
JOIN details_commandes dc2 ON c.no_commande = dc2.no_commande
WHERE dc.ref_produit = 30 AND dc2.ref_produit = 74

-- 21-Donner le code des clients espagnols qui n'ont pas commandé.
-- Donner 3 écritures.
-- 1 ligne : FISSA
SELECT c.code_client
FROM clients c 
WHERE c.pays ='Espagne'
EXCEPT
SELECT code_client 
FROM commandes c 

SELECT c.code_client
FROM clients c 
WHERE c.pays ='Espagne' 
AND c.code_client NOT IN (
	SELECT code_client 
	FROM commandes c )


-- 22-Donner le numéro des commandes de aout 2008 des clients
-- habitant au Royaume-Uni ou à Toulouse.
-- Afficher le jour de la commande.
-- 3 lignes
SELECT c.no_commande
FROM commandes c 
JOIN clients c2 ON c.code_client = c2.code_client
WHERE c.date_commande > '2008-07-30' 
AND c.date_commande < '2008-09-01' 
AND (c2.pays = 'Royaume-Uni' OR c2.ville ='Toulouse')

-- 23-Donner le code et le pays des clients ayant commandé le produit n°31.
-- Afficher le pays sous cette forme : Aut. (3 premières lettres + point).
-- 14 lignes

SELECT * 
FROM 

-- 24-Donner le code et la société des clients de catégorie 1 avec le numéro de leurs commandes
-- (on veut afficher tous les clients même ceux qui n'ont pas encore de commande).
-- Trier les lignes par société puis par numéro de commande décroissant.
-- 97 lignes

-- 25-Requête 4 avec une jointure externe (anti-jointure).
-- 1 ligne : FISSA

-- 26-Donner la référence des produits qui coûtent plus de 300€ ou qui ont été commandés par 50.
-- (union ou jointure)
-- 17 lignes

-- 27-Donner la référence des produits qui coûtent plus de 300€ ou qui ont été commandés par 50.
-- (intersection ou jointure)
-- 2 lignes

-- 28-Donner le numéro et le nom des produits qui n'ont pas été commandés.
-- (plusieurs solutions dont anti-jointure)
-- 1 ligne : 18

-- 29-Donner le numéro et la date des commandes contenant les produits 30 et 74.
-- 1 ligne : 10263

-- 30-Donner les sociétés dont le pays est le même que celui de la société FRANS.
-- 2 lignes

-- 31-Donner les produits dont le prix est supérieur au prix moyen des produits.
-- 21 lignes

-- 32-Donner le nombre de clients qui ont commandé le produit n° 31.
-- 1 ligne : 14

-- 33-Donner la référence et le nom du ou des produits les plus chers.
-- 1 ligne : 9

-- 34-Donner le nombre de clients de catégorie 0 ou 1 par pays (sauf la France).
-- Trier par nombre décroissant.
-- 9 lignes

-- 35-Donner le nombre de clients par pays et par catégorie.
-- Trier par pays, catégorie.
-- 24 lignes

-- 36-Donner les pays ayant des sociétés d'au moins 2 catégories différentes.
-- 6 lignes

-- 37-Donner le nombre de produits total par commande (uniquement si au moins 4 références différentes).
-- 21 lignes

-- 38-Donner la référence des commandes dont le montant est supérieur à 20000
-- (afficher le montant total de la facture).
-- Vérifier le résultat pour une facture.
-- 9 lignes

-- 39-Donner le numéro et la date des commandes avec au moins 4 références différentes.
-- 21 lignes


/* *********************************
        Niveau avancé :
************************************ */


-- 40-Donner les produits commandés en même quantité dans une même commande
-- (uniquement si la quantité est supérieure à 45).
-- 4 lignes

-- 41-Donner pour chaque produit, les produits qui coutent 10€ de plus.
-- Afficher les références et les prix des produits
-- Trier par produit.
-- 30 lignes

-- 42-Requête 4 avec un NOT EXISTS.
-- Forme : SELECT ... FROM ... WHERE EXISTS / NOT EXISTS (SELECT * FROM ... WHERE ...)
-- Il y a toujours un lien entre les deux sous-requêtes (grâce à la notation pointée).
-- 1 ligne : FISSA

-- 43-Donner le numéro des commandes contenant tous les produits qui coutent 105€.
-- 1 ligne : 10698

-- 44-Donner la référence des produits qui sont dans toutes les commandes de FRANR.
-- 1 ligne : 62

-- 45-Donner la référence du produit qui a été le plus commandé.
-- 1 ligne : 31

-- 46-Donner le numéro des commandes de 2010 (avec le code des clients) contenant tous les produits les plus chers.
-- 1 ligne : 10848
